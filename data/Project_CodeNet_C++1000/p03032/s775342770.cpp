#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    int mx = min(K, N);

    int V[N];
    for(int i=0; i<N; i++) cin >> V[i];

    ll ans = 0;
    //  取る個数
    for(int i=1; i<=mx; i++){
        // 左からl個、右からr個
        for(int l=0; l<=i; l++){
            int r = i-l;

            vector<int> s;
            for(int i=0; i<l; i++) s.push_back(V[i]);
            for(int i=0; i<r; i++) s.push_back(V[N-1-i]);

            sort(s.begin(), s.end());

            int ret = K - i;
            int cnt = 0;
            ll ta = 0;
            // cout << "---------" << endl;
            // cout << i << " " << l << " " << r << " " << ret << endl;
            for(int i=0; i<s.size(); i++){
                // cout << s[i] << endl;
                if(cnt < ret && s[i] < 0){
                    cnt++;
                    continue;
                }
                ta = ta + s[i];
            }
            ans = max(ta, ans);
        }
    }
    
    cout << ans << endl;

    return 0;
}
