#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string s[4] = {"", "KIH", "B", "R"};
    string str;
    cin >> str;
    ll ans = 0;
    for(ll i = 0; i < 16; i++){
        string tmp = "";
        for(ll j = 0; j < 4; j++){
            tmp += s[j];
            if(i & (1 << j))tmp += "A";
        }
        if(tmp == str)ans = 1;
    }
    Say(ans, "YES", "NO");

    return 0;
}