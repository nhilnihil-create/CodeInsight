#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n,h,w;
    cin >> n >> h >> w;
    int ans = 0;
    int a,b;
    REP(i,n){
        cin >> a >> b;
        if(a >= h && b >= w){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}