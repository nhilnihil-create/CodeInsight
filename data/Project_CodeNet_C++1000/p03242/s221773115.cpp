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
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            cout << '9';
        else
            cout << '1';
    }
    cout << endl;
    return 0;
}
