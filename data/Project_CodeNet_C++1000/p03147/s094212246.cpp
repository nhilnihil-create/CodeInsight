#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main() {
    int N;
    cin >> N;
    int h[N];
    rep(i,N) {
        int tmp;
        cin >> tmp;
        h[i] = tmp;
    }
    int ans = 0;
    while(1) {
        int cnt = 0;
        bool c = false;
        rep(i,N) {
            if(!c && h[i]>0) {
                cnt++;
                c=true;
            } 
            else if (c && h[i]==0) {
                c=false;
            }
            
            if (h[i]>0) h[i]--;
        }
        ans += cnt;
        if (cnt==0) {
            break;
        }
    }
    cout << ans << endl;
}
