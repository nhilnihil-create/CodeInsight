#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    string s;
    cin >> s;
    int c=0;
    REP(i,4) c+=(s[i]=='2'?1:0);
    cout << c << endl;
}
