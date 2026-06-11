#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

bool isPrime(int n) {
    int i;

    if (n<2) return false;
    else if (n==2) return true;
    if (n%2==0) return false;
    for(i=3;i*i<=n;i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

int main(void) {
    int q;
    cin >> q;

    vector<int> l(q);
    vector<int> r(q);

    for(int iq=0;iq<q;iq++) {
        cin >> l.at(iq) >> r.at(iq);
    }

    vector<int> sum(100001, 0);
    vector<bool> yn(100001, false);

    int n=100000;
    for(int in=1;in<=n;in++) {
        sum.at(in) = sum.at(in-1);
        if(in%2==1&&isPrime(in)&&isPrime((in+1)/2))  {
            sum.at(in)++;
            yn.at(in) = true;
        }
    }

    int ans;
    for(int iq=0;iq<q;iq++) {
        ans = sum.at(r.at(iq))-sum.at(l.at(iq)-1);
        // if(yn.at(r.at(iq))) ans++;
        // if(yn.at(l.at(iq))) ans++;
        // if(yn.at(r.at(iq))&&yn.at(l.at(iq))) ans--;
        cout << ans << endl;
    }
    return 0;
}
