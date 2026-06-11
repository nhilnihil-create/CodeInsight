#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main()
{
    ll N,M;
    cin >> N>>M;

    ll num = N;
    int cnt=0;
    while(num<=M){
        //cout << num << endl;
        cnt++;
        num *=2;
    }

    cout << cnt << endl;

    
    return 0;
}