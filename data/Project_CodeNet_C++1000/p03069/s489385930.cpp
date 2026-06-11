#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int cw[200020], cb[200020], ct[200020];

int main(void)
{
    int n;     cin >> n;
    string s;  cin >> s;
    cw[n] = cb[0] = 0;
    REP(i, n+1) {
        cb[i+1] += (cb[i] + (s[i]=='#'?1:0));
        cw[n-i-1] += (cw[n-i] + (s[n-i-1]=='.'?1:0));
    }
    int  m = 3*10e5;
    REP(i, n+1) {
//        cout << i << " " << cb[i] << " " << cw[i] << endl;
        m = min(m, cb[i]+cw[i]);
    }
    cout << m << endl;
}
