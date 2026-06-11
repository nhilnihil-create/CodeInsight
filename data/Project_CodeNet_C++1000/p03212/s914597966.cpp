#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define dump(x)
#define debug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N){
    int answer = 0;
    stack<int> s;
    ll n = 0, cntSum = 0;
    vector<int> cnt(10);
    s.push(0);
    while (!s.empty()) {
        ll current = s.top();
        s.pop();
        if (current>=0) {
            if (current!=0 && cntSum<10) {
                n += current * pow(10,cntSum);
                cnt[current]++;
                cntSum++;
            }

            if (n <= N && cnt[3]>0&&cnt[5]>0&&cnt[7]>0) answer++;

            if (n <= N) {
                for (const int j : {-3,3,-5,5,-7,7}) {
                    s.push(j);
                }
            }
        } else if (current<0) {
            cntSum--;
            cnt[-current]--;
            n -= -current * pow(10,cntSum);
        }
    }
    cout << answer << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
