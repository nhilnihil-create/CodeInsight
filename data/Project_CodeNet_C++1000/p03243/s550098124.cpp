#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

string s;

int main()
{
    _FastIO;
    cin >> s;
    if(int(s[0]) > int(s[1])){
        cout << s[0] << s[0] << s[0] << endl;
        return 0;
    }
    if(int(s[0]) == int(s[1]) && int(s[1]) >= int(s[2])){
        cout << s[0] << s[0] << s[0] << endl;
    }
    else{
        char c = char(int(s[0]) + 1);
        cout << c << c << c << endl;
    }
    return 0;
}
