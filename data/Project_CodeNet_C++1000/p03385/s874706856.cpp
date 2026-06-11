#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<bool> check(3,false);
    for(int i=0;i<s.length();i++){
        check[s[i]-'a']=true;
    }
    for(int i=0;i<3;i++){
        if(check[i]==false){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}