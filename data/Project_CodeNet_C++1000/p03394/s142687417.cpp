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
    if (N <= 6 && N != 5) {
        if (N == 3) {
            cout << "2 5 63" << endl;
        } else if (N == 4) {
            cout << "2 5 20 63" << endl;
        } else if (N == 6) {
            cout << "2 5 20 63 180 360" << endl;
        }
        return;
    }
    vector<int> two = {2,4,6}, three = {3,9}, five;
    int remain = N - 5;
    int current = 8;
    while (remain > 2 && current+4 <= 30000) {
        two.push_back(current);
        two.push_back(current+2);
        two.push_back(current+4);
        current += 6;
        remain -= 3;
    }
    while (remain % 2 != 0) {
        two.pop_back();
        two.pop_back();
        two.pop_back();
        remain += 3;
    }
    current = 15;
    while (remain > 0 && current+6 <= 30000) {
        three.push_back(current);
        three.push_back(current+6);
        current += 12;
        remain -= 2;
    }
    if (remain > 0) {
        while (two.size() % 5 != 0) {
            rep(i,0,3) {
                two.pop_back();
                remain++;
            }
        }
        while (three.size() % 5 != 0) {
            rep(i,0,2) {
                three.pop_back();
                remain++;
            }
        }
        rep(i,1,30001) {
            if (remain == 0) break;
            if (i % 5 == 0 && i % 2 != 0 && i % 3 != 0) {
                five.push_back(i);
                remain--;
            }
        }
    }
    vector<int> answer = two;
    copy(all(three), back_inserter(answer));
    copy(all(five), back_inserter(answer));
    rep(i,0,N) {
        cout << answer[i] << (i==N-1 ? "\n" : " ");
    }
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
