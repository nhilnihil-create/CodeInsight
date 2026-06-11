#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    for(int i = 0; i < a; i++){
        if(s[i] >= 48 && s[i] <= 57)continue;
        else{
            cout << "No";
            return 0;
        }
    }
    for(int i = a+1; i < s.size(); i++){
        if(s[i] >= 48 && s[i] <= 57)continue;
        else{
            cout << "No";
            return 0;
        }
    }
    if(s[a] == '-' && s.size() == a + b + 1){
        cout << "Yes";
    }
    else cout << "No";
        
}