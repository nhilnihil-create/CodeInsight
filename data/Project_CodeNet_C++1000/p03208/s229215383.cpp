#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans=INF;
    sort(all(h));
    rep(i,n-k+1){
        ans=min(ans,h[i+k-1]-h[i]);
    }
    cout << ans << endl;
return 0;
}
