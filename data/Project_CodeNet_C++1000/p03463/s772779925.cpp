#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(10e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << (((b - a)%2==0)?"Alice":"Borys") << endl; 
}
