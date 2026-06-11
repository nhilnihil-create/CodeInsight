#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define inin freopen("input2.txt", "r", stdin)


int main(){
	//inin;
    IOS
	ll n,c;
	cin>>n>>c;
	ll a[n+1][n+1];
	ll d[c+1][c+1];
	FOR(i,1,c){
		FOR(j,1,c){
			cin>>d[i][j];
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			cin>>a[i][j];
		}
	}

	map<ll,ll> zer;

     map<ll,ll> one;	
     map<ll,ll> two;
     FOR(i,1,n){
		FOR(j,1,n){
			if((i+j)%3==0){
				zer[a[i][j]]++;
			}
			if((i+j)%3==1){
				one[a[i][j]]++;
			}
			if((i+j)%3==2){
				two[a[i][j]]++;
			}
		}
	}
	ll tmp;
	ll ans=10000000000000;
	FOR(i,1,c){
		FOR(j,1,c){
			FOR(k,1,c){
				if(j!=i&&k!=j&&k!=i){
					tmp=0;
					for(auto oo:zer){
						if(oo.first!= i) tmp+=(oo.second*d[oo.first][i]);
					}
					for(auto oo:one){
						if(oo.first!= j) tmp+=(oo.second*d[oo.first][j]);
					}
					for(auto oo:two){
						if(oo.first!= k) tmp+=(oo.second*d[oo.first][k]);
					}
					ans=min(ans,tmp);
				}
			}
		}
	}
	cout<<ans<<endl;

}