#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int main() {FIN;
    int n,k; cin>>n>>k;
    vector<int> v(n);
    fore(i,0,n) cin>>v[i];
    bool dp[k+1]; memset(dp,false,sizeof(dp));
    fore(i,0,k+1){
        fore(j,0,n) if(v[j]<= i) dp[i] |= !dp[i-v[j]];
    }
    if(dp[k]) cout<<"First\n";
    else cout<<"Second\n";
    return 0;
}

