#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
int main(){
	ll n,y;
	cin>>n>>y;
	ll maxbill = y/1000;
	if(n>maxbill) cout<<-1<<" "<<-1<<" "<<-1;
	else if(n==maxbill) cout<<0<<" "<<0<<" "<<maxbill;
	else{
		ll diff = maxbill-n;
		// 9a + 4b = diff;
		for(int i=0; i<=diff; i++){
			for(int j=0; j<=diff; j++){
				if(9*i+4*j==diff && n-j-i>=0){
					cout<<i<<" "<<j<<" "<<n-j-i;
					return 0;
				}
			}
		}
		cout<<-1<<" "<<-1<<" "<<-1;
	}
}