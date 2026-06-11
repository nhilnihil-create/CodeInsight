#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    string s[5];
    int idx = 0;
    while(cin >> s[idx++]);
    string temp = s[0];
    if(s[1].size() > 0){
        reverse(temp.begin(), temp.end());
        string temp2 = s[1];
        reverse(temp2.begin(), temp2.end());
        if(temp2 == s[0] && temp == s[1])
            return cout << "YES", 0;
        cout << "NO";
    }
    else{
        reverse(temp.begin(), temp.end());
        if(temp == s[0])
            return cout << "YES", 0;
        cout << "NO";
    }
    return 0;
}