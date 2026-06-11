#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,M;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;

if(N==1&&M==1) cout<<1<<endl;
else if(N==1&&M>1) cout<<M-2<<endl;
else if(N>1&&M==1) cout<<N-2<<endl;
else if(N==2&&M>1) cout<<0<<endl;
else if(N>1&&M==1) cout<<0<<endl; 
else cout<<(N-2)*(M-2)<<endl;


}
	
