#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main(){
    double t,x;cin >> t >> x;
    cout << double(t/x) << endl;
    return 0;
}