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
    int n;
    cin >> n;
    vector<int> nums = {3, 5, 7};
    rep (i, 8) {
        vector<int> cp = nums;
        for (int e: nums) {
            if (e < pow(10, i)) {
                continue;
            }
            int p = e * 10;
            for (int j = 3; j < 8; j += 2) {
                cp.push_back(p + j);
            }
        }
        nums = cp;
    }
    int ctr = 0;
    for (auto num: nums) {
        if (num > n) {
            continue;
        }
        bool three, five, seven;
        three = five = seven = false;
        while (num > 0) {
            int d = num % 10;
            switch (d) {
                case 3:
                    three = true;
                    break;
                case 5:
                    five = true;
                    break;
                case 7:
                    seven = true;
                    break;
            }
            num /= 10;
        }
        if (three && five && seven) {
            ctr++;
        }
    }
    cout << ctr << endl;
}