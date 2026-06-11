#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
#define OUT(n) cout << (n) << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    int t = min(a,b);
    int u = min(c,d);
    OUT(t+u) 

    return 0;
}