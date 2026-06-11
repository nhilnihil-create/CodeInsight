#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    string s;
    cin >> s;
    int n = s.length();

    string ans;
    for(int i=0; i<7; ++i){
        string fs = s.substr(0, i);
        string ls = s.substr(n-7+i);
        ans = fs+ls;

        if(ans == "keyence"){
            cout << "YES";
            return 0;
        }

    }

    cout << "NO";
}
