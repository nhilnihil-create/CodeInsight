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
    int d;cin >> d;

    if(d==25)cout << "Christmas" << endl;
    else if(d==24)cout << "Christmas Eve" << endl;
    else if(d==23)cout << "Christmas Eve Eve" << endl;
    else if(d==22)cout << "Christmas Eve Eve Eve" << endl;

    return 0;
}