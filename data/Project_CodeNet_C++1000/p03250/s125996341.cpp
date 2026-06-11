#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i,e) for(ll i=0;i<e;i++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT32_MAX;

ll i,j;





int main(){
   ll A,B,C;
   cin>>A>>B>>C;
   cout<<10*max(A,max(B,C))+(A+B+C)-max(A,max(B,C))<<endl;
}