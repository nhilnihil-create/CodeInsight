#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    ll ans = 0;
    ll cou = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'A'){
            cou++;
        }else{
            if(s.substr(i, 2) == "BC"){
                ans += cou;
                i++;
            }else{
                cou = 0;
            }
        }
    }

    cout << ans << endl;
}