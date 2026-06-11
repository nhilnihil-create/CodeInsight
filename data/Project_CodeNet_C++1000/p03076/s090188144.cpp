#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define sz(x) (int)x.size() 
typedef long long ll;
using namespace std;

int T[5];

int main() {
	
	forn(i,5) cin>>T[i];
	ll mn=1e9;
	do{
		ll cost=0;
		forn(i,5){
			int x=(T[i]+9)/10;
			cost+=T[i]+(i==4?0:(10*x-T[i]));
		}
		mn=min(mn,cost);
	}while(next_permutation(T,T+5));
	cout<<mn<<endl;
	return 0;
}