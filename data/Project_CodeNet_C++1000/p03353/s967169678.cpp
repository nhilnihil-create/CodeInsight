#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+7;
string s;
int k;
set<string> ans;
int main()
{
    cin >> s >> k;
    int len = s.length();
    for(int i = 0; i < len; ++i) {
        for(int j = 1; j <= 5; ++j) {
            if(i+j-1 >= len) continue;
            ans.insert(s.substr(i, j));
        }
    }
    set<string>::iterator iter = ans.begin();
    int i = 1;
    for(; i != k; ++iter, ++i);
    cout << *iter << endl;
}