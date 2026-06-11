#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,t; cin >> n >> t;
    int ans=INF;
    rep(i,n){
        int c,d; cin >> c >> d;
        if(d>t) continue;
        ans=min(ans,c);
    }
    if(ans==INF) cout << "TLE" << endl;
    else cout << ans << endl;
return 0;
}
