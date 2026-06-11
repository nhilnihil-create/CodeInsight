#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;

    bool check=false;
    for(int i=0;i<s.length();i++){
        if(s==t){
            check=true;
            break;
        }
        s=s[s.length()-1]+s;
        s.erase(s.length()-1);
    }
    if(check) cout << "Yes" << endl;
    else cout << "No" << endl;
}