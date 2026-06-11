#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,k; cin>>a>>b>>k;
	int n=b-a+1;
	if(2*k>=n){
		for(int i=a; i<=b; i++) cout<<i<<endl;
	}else{
		for(int i=a; i<a+k; i++) cout<<i<<endl;
		for(int i=b-k+1; i<=b; i++) cout<<i<<endl;
	}
}