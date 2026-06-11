#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, a[200200], b[200200], c[200200], d[200200], ans;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < N; j++){
            c[j] = b[j] % (1ll << (i + 1));
            d[j] = a[j] % (1ll << (i + 1));

        }
        sort(c, c + N);
        int cnt = 0;
        for(int j = 0; j < N; j++){
            cnt += lower_bound(c, c + N, (1ll << (i + 1)) - d[j]) - lower_bound(c, c + N, (1ll << i) - d[j]);
            cnt += lower_bound(c, c + N, (1ll << (i + 2)) - d[j]) - lower_bound(c, c + N, (1ll << (i + 1)) + (1ll << i) - d[j]);
        }
        if(cnt % 2){
            ans += (1ll << i);
        }
    }
    cout << ans << endl;

    return 0;
}

/*



*/
