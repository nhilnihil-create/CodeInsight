#include <iostream> 
using namespace std;

int sushu[100001]={0};//素数表 
int qianzhui[100001]={0};//前缀和 
void sieve(){
	for(int i=2;i*i<=100000;i++){
		if(sushu[i]==0){//合数的倍数不需要再做筛选 
			for(int j=2;i*j<100000;j++){
			    //要把合数下标置1
			    sushu[i*j]=1;
		    }
		}
	}
}
int main(){
	int q,l,r;
	cin>>q;
	sieve();
	sushu[1]=1;
	sushu[2]=1;
	for(int i=1;i<=100000;i++){
		if(sushu[i]==0&&sushu[(i+1)/2]==0&&i!=2||i==3){
			qianzhui[i]=qianzhui[i-1]+1;
		}else{
			qianzhui[i]=qianzhui[i-1];
		}
	}
	for(int j=1;j<=q;j++){
		cin>>l>>r;
		cout<<qianzhui[r]-qianzhui[l-1]<<endl;
	} 
    return 0;
}