#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll a = 0,b = 0,c = 0;
    for (ll i = 0; i < s.size(); i++){
        if (s[i] == 'a'){
            a++;
        }
        else if (s[i] == 'b'){
            b++;
        }
        else{
            c++;
        }
    }
    if (max(max(a,b),c) - min(min(a,b),c) <= 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}