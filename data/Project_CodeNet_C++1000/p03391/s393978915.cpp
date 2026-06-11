#include<iostream>
using namespace std;
typedef long long int LL;
const int INF=1e9+7;
int main(){
	int n;
	LL a,b,c;
	int i,j,k;
	LL s=0;
	cin>>n;
	for(c=INF,i=0;i<n;i++){
		cin>>a>>b;
		if(a>b && c>b)c=b;
		s+=a;
	}
	if(c==INF)cout<<0<<endl;
	else cout<<s-c<<endl;
}
	
