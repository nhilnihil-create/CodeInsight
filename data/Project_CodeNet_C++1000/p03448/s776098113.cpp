#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a,b,c,x;
	cin>>a>>b>>c>>x;
	ll co=0;
	for(ll i=0; i<=a; i++){
		for(ll j=0; j<=b; j++){
			for(ll k=0; k<=c; k++){
				if(i*500+j*100+k*50==x){
					co++;
				}

			}
		}
	}
	cout<<co;

}