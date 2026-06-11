#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


int main() {
    ll A,B,K;
    cin >> A >> B >> K;

    int k = 0;
    while(k!=K) {

        // takahashi tern
        if (A%2==1) A--;
        B+=(A/(ll)2);
        A/=(ll)2;
        k++;
        if (k==K) break;

        // aoki tern
        if (B%2==1) B--;
        A+=(B/(ll)2);
        B/=(ll)2;
        k++;

    }

    cout << A << " " << B << endl;

    return 0;
}
