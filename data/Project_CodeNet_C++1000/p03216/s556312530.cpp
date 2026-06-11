//AC済 バチャ用再提出
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
    ll bBeforeSum[1000005];
    ll bsum[1000005];
    ll csum[1000005];
    ll bBefore[1000005];

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    int q;
    cin >> q;
    bsum[0] = 0;
    csum[0] = 0;
    if(s[0] == 'M') bsum[0]++;
    if(s[0] == 'C') csum[0]++;
    for(int i = 1; i <= n; i++){
        bsum[i] = bsum[i - 1];
        csum[i] = csum[i - 1];
        if(s[i] == 'M')bsum[i]++;
        if(s[i] == 'C')csum[i]++;
    }
    //cout << "a" << endl;
    int now = 0;
    bBefore[0] = 0;
    bBeforeSum[0] = 0;
    if(s[0] == 'M') now++;
    for(int i = 1; i <= n; i++){
        //cout << i << endl;
        bBefore[i] = 0;
        if(s[i] == 'M'){
            now++;
        }
        if(s[i] == 'C'){
            bBefore[i] = now;
        }
        bBeforeSum[i] = bBeforeSum[i - 1] + bBefore[i];
    }
    for(int i = 0; i <= n; i++){
        //cout << i << " BSum " << bsum[i] << " bBefore " << bBefore[i] << " " << endl;
    }
    for(int times = 0; times < q; times++){
        int k;
        cin >> k;
        ll ans = 0;
        for(int index = 0; index <= n; index++){
            if(s[index] != 'D') continue;
            int end = min(index + k - 1, n);
            ll NC = csum[end] - csum[index - 1];
            //cout << index << " " << (bBeforeSum[end] - bBeforeSum[index - 1]) - NC * bsum[index - 1] << endl;
            ans += (bBeforeSum[end] - bBeforeSum[index - 1]) - NC * bsum[index - 1];
        }
        cout << ans << endl;
    }
    return 0;
}
