#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    int n;
    string s;
    cin >> n >> s;
    int cnt  = 0;
    REP(i, n) cnt+=(s[i]=='R')?1:-1;
    cout << ((cnt >0)?"Yes":"No") << endl;
}
