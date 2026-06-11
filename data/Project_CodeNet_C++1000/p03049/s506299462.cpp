#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

string s[10010];

int main(void)
{
    int n;
    cin >> n;
    REP(i, n) cin >> s[i];
    int cnt = 0, ca = 0, cb = 0, cab = 0,a,b;
    REP(i, n) {
        REP(j, s[i].length()-1) {
            if(s[i][j] == 'A' && s[i][j+1] == 'B') cnt++;
        }
        a = (s[i][s[i].length()-1] == 'A')?1:0;
        b = (s[i][0] == 'B')?1:0;
        if(a+b==2) {
            cab ++;
        } else {
            ca += a;
            cb += b;
        }
    }
    if(cab==0) {
        cnt += min(ca,cb);
    } else {
        if(ca+cb>0) {
            cnt += cab+min(ca,cb);
        } else {
            cnt += cab-1;
        }
    }
    cout << cnt << endl;

}
