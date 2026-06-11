#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string ans="Yes";
    map<string,int> check;
    
    string s;
    string s_before;
    cin >> s_before;
    check[s_before]=1;
    for(int i=1;i<n;i++){
        cin >> s;

        if(check[s]==1) ans="No";
        check[s]=1;

        if(s[0]!=s_before[s_before.length()-1]) ans="No";
        s_before=s;
    }
    cout << ans << endl;
}