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

int main(){
    int n;cin >> n;
    int p[n];rep(i,n)cin >> p[i];

    int num=0,sum=0;
    rep(i,n){
        num = max(num,p[i]);
        sum += p[i];
    }

    cout << sum -num/2 << endl;
    return 0;
}