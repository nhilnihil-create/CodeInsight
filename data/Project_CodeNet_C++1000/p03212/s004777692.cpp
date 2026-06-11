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

int dfs(const int N, const int n, vector<int>& cnt, int digits=0) {
    if (n > N) return 0;
    int sum = 0;
    for (const int i : {3,5,7}) {
        if (digits==9) break;
        cnt[i]++;
        sum += dfs(N, n+i*pow(10,digits), cnt, digits+1);
        cnt[i]--;
    }
    if (cnt[3]&&cnt[5]&&cnt[7]) sum++;
    return sum;
}

void solve(long long N){
//    int answer = 0;
//    stack<int> s;
//    int n = 0, cntSum = 0;
//    vector<int> cnt(10);
//    vector<vector<int>> pows(10,vector<int>(10));
//    rep(i,0,10) for (const int j : {3,5,7}) pows[i][j] = j * pow(10, i);
//    s.push(0);
//    while (!s.empty()) {
//        int current = s.top();
//        s.pop();
//        if (N==575) debug(current);
//        if (current>=0) {
//            if (current!=0 && cntSum<10) {
//                n += pows[cntSum][current];
//                //n += current * pow(10,cntSum);
//                cnt[current]++;
//                cntSum++;
//                if (N==575) {
//                    debug(n);
//                }
//            }
//
//            if (n <= N && cnt[3]>0&&cnt[5]>0&&cnt[7]>0) answer++;
//
//            if (n <= N) {
//                for (const int j : {-3,3,-5,5,-7,7}) {
//                    s.push(j);
//                }
//            }
//        } else if (current<0) {
//            cntSum--;
//            cnt[-current]--;
//            n -= pows[cntSum][-current];
//            //n -= -current * pow(10,cntSum);
//        }
//    }
    vector<int> cnt(10);
    cout << dfs(N,0,cnt) << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
