#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define pb push_back
int main(){
	int n,k;
	cin>>n>>k;
	double pos=0;
	for(int i=1;i<n+1;i++){
		int j=i;
		double p=1;
		while(j<k){
			j*=2;
			p/=2;
		}
		pos+=p;
	}
	pos/=n;
	cout<<setprecision(20)<<pos<<endl;
}
