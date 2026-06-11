#include<bits/stdc++.h>
#define int long long
#define re(i,n) for(i=0;i<n;i++)
#define bre(i,n) for(i=n;i>0;i--)
#define rep(i,l,r) for(i=l;i<r;i++)
#define brep(i,l,r) for(i=r;i>l;i--)
const int inf=1145141919810893;
const int mod=998244353;
using namespace std;
template<class T>bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}
	return false;
}
template<class T>bool chmax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
template<class T>void debug(T *a,int l,int r,const char *name){
	for(int i=l;i<r;i++)
		cout<<name<<"["<<i<<"]="<<a[i]<<endl;
}
template<int H,int W>int wa(int x1,int y1,int x2,int y2,int(&p)[H][W]){
	return p[y2][x2]-p[y2][x1]-p[y1][x2]+p[y1][x1];
}
struct Unif{
	vector<int> e;
	vector<int> rank;
	Unif(int n):e(n,-1),rank(n,1){}
	void uni(int a,int b){
		if(e[a]!=-1)
			uni(e[a],b);
		else if(e[b]!=-1)
			uni(a,e[b]);
		else{
			if(a==b)
				return;
			int ra=rank[a],rb=rank[b];
			if(ra>=rb){
				e[b]=a;
				if(ra==rb)
					rank[a]++;
			}
			else
				e[a]=b;
		}
	}
	bool find(int a,int b){
		if(e[a]!=-1)
			return find(e[a],b);
		else if(e[b]!=-1)
			return find(a,e[b]);
		else
			return a==b;
	}
	int num(int a){
		if(e[a]!=-1)
			return num(e[a]);
		else
			return a;
	}
};
int A,B,C,D,N,M,K,S,T,H,W,Q;
signed main(){
	int i,j,k;
	cin>>Q;
	re(i,Q){
		cin>>A>>B;
		if(A==B){
			cout<<A+B-2<<endl;
			continue;
		}
		double r=sqrt(static_cast<double>(A)*static_cast<double>(B));
		int x=floor(r),y=ceil(r);
		if(x==y&&x*y>=A*B)
			x--;
		else if(x*y>=A*B)
			y--;
		cout<<x+y-2<<endl;
	}
}