#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    ll a[N];
    ll sum[N + 1];
    sum[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int l[N]; //真ん中の切れ込みがiのときの最適な左の切れ込みの位置
    int r[N]; //真ん中の切れ込みがiのろきの最適な右の切れ込みの位置

    l[2] = 1;
    for(int i = 3; i < N - 1; i++){
        l[i] = l[i - 1];
        while(true){
            if(l[i] == i - 1) break;
            else {
                if(abs(sum[i] - 2 * sum[l[i]]) > abs(sum[i] - 2 * sum[l[i] + 1])){
                    l[i]++;
                } else {
                    break;
                }
            }
        }
    }

    r[N - 2] = N - 1;
    for(int i = N - 3; i >= 2; i--){
        r[i] = r[i + 1];
        while(true){
            if(r[i] == i + 1) break;
            else {
                ll x = abs((sum[N] - sum[r[i]]) - (sum[r[i]] - sum[i]));
                ll y = abs((sum[N]) - sum[r[i] - 1]) - (sum[r[i] - 1] - sum[i]);
                if(y < x) r[i]--;
                else break;
            }
        }
    }

    /*
    for(int i = 0; i < N; i++){
        cout << i << " " << l[i] << " " << r[i] << endl;
    }*/

    ll ans = (1LL << 60);
    for(int i = 2; i < N - 1; i++){
        vector<ll> v;
        v.push_back(sum[l[i]]);
        v.push_back(sum[i] - sum[l[i]]);
        v.push_back(sum[r[i]] - sum[i]);
        v.push_back(sum[N] - sum[r[i]]);

        ll d = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        ans = min(ans, d);
    }

    cout << ans << endl;

    return 0;
}