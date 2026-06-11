#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char,int>mp;
    mp[s[0]]++;
    mp[s[1]]++;
    mp[s[2]]++;
    if(mp['a']==1 && mp['b']==1 && mp['c']==1 )
        cout << "Yes" << endl;
    else cout << "No" << endl;
}
