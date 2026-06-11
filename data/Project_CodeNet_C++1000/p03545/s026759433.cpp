#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,m,n) for (int i = m; i < (n); ++i)
#define REPR(i,n) for (int i = n; i >= 0; --i)
#define P pair<int, int>
const int INF = 1e9;
using namespace std;

const int NUM = 4;
//vector<int> a(NUM);
int a[NUM];

int main() {
    int n;
    cin >> n;
    REPR(i,3) {
        a[i] = n%10;
        n/=10;
    }
    // reverse(a.begin(), a.end());
    // scanf("%d", &a);
    //cin >> a[0] >> a[1] >> a[2] >> a[3];
    REP(x,8) {
        int sum = a[0];
        string s;
        s += (char)('0'+ a[0]);
        REP(i,3) {
            if(x&(1<<i)) {
                sum += a[i+1];
                s += '+';
                s += (char)('0' + a[i+1]);
            } else {
                sum -= a[i+1];
                s += '-';
                s += (char)('0' + a[i+1]);
            }
        }
        if(sum==7) {
            cout << s << "=7" <<  endl;
            break;
        }
    }
}