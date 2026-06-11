#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()




int main() {
    vector<int> primes;
    for (int num = 6; num <= 55556; num += 5) {
        bool flag = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.push_back(num);
        }
    }
    int n;
    cin >> n;
    rep (i, n) {
        if (i) {
            cout << " ";
        }
        cout << primes[i];
    }
    cout << endl;
}

