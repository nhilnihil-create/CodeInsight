#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long int LL;
const LL MAX=2e9;
LL pos[1005][2];
 
void check(int a,int t){
	int i,j,k;
	t=1<<t;
	if(abs(pos[a][0])>abs(pos[a][1])){
		if(pos[a][0]>0){
			cout<<'R';
			pos[a][0]-=t;
		}else{
			cout<<'L';
			pos[a][0]+=t;
		}
	}else{
		if(pos[a][1]>0){
			cout<<'U';
			pos[a][1]-=t;
		}else{
			cout<<'D';
			pos[a][1]+=t;
		}
	}
}
 
int main(){
	int n;
	int i,j,k;
	LL a,b,c,d;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>pos[i][0]>>pos[i][1];
	}
	a=(pos[0][0]+pos[0][1]+MAX)%2;
	for(i=0;i<n;i++){
		b=(pos[i][0]+pos[i][1]+MAX)%2;
		if(a!=b){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<(32-a)<<endl;
	for(i=30;i>0;i--){
		cout<<(1<<i)<<" ";
	}
	if(a==1)cout<<1<<endl;
	else cout<<1<<" "<<1<<endl;
	
	for(i=0;i<n;i++){
		for(j=30;j>=0;j--){
			check(i,j);
		}
		if(a==0)check(i,0);
		cout<<endl;
	}
	
	return 0;
	
}
