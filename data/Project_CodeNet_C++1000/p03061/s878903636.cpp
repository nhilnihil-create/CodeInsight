#include<iostream>
using namespace std;
//セグ木
int GCD(int x,int y){
	return x%y==0?y:GCD(y,x%y);
}
class segment{
typedef int segClass;
public:
	segClass *tree;
	segClass u;
	int height,treeSize,dataSize;
	segment(long long int length,segClass unit){
		long long int pre = 1;
		height=1;
		u=unit;
		
		while(pre<length){
			pre*=2;
			height++;
		}
		
		treeSize = pre*2-1;
		dataSize = pre;
		tree = new segClass[treeSize];
		
		for(int i=0;i<dataSize;i++)set(i,unit);
		construct();

	}
	void replace(long long int index, segClass value){
		tree[treeSize-dataSize+index]=value;
		index=treeSize-dataSize+index+1;
		while(index>0){
			index/=2;
			tree[index-1]=f(tree[index*2-1],tree[index*2]);
		}
	}
	segClass result(long long int l,long long int r){return result(l,r,0,1<<(height-1),0);}
	segClass result(long long int l,long long int r,int s,int len,long long int ind){
		if(l==r)return get(l);
		else if(l==s && r==s+len-1)return tree[ind];
		len/=2;
		
		segClass res=u;
		long long int L=s,R=s+len-1;
		if(!(r<L || R<l))res=f(result(max(L,l),min(R,r),L,len,ind*2+1),res);
		L+=len;R+=len;
		if(!(r<L || R<l))res=f(result(max(L,l),min(R,r),L,len,ind*2+2),res);
		return res;
	}
	
	void construct(){for(int i=treeSize-2;i>0;i-=2)tree[i/2]=f(tree[i],tree[i+1]);}
	void set(long long int index, segClass value){tree[treeSize-dataSize+index]=value;}
	segClass get(long long int index){return tree[treeSize-dataSize+index];}
	
	segClass f(segClass a,segClass b){
		if(a==0)return b;
		else if(b==0)return a;
		else return GCD(a,b);
	}
};

int main(){
	int N,A,ans=1;
	cin>>N;
	segment seg(N,0);

	for(int i=0;i<N;i++){
		cin>>A;
		seg.set(i,A);
	}
	
	seg.construct();
	for(int i=1;i<N-1;i++)ans=max(ans,GCD(seg.result(0,i-1),seg.result(i+1,N-1)));
	ans=max(ans,seg.result(1,N-1));
	ans=max(ans,seg.result(0,N-2));
	cout<<ans;
	return 0;
}