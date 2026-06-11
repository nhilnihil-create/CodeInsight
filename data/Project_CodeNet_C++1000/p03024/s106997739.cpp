#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)
 
 
int main()
{
    string s;
    cin >> s;
    int a = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'x') a++;
    }
    cout << (a >= 8 ? "NO" : "YES") << endl;
    return 0;
}