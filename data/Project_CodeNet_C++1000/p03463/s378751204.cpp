#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
typedef long long ll;
using ll = long long;
using vi = vector<int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if((c - b) % 2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}
