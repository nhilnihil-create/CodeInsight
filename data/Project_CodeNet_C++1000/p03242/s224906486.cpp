#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s, t = ""; cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            t += "9";
        }
        else if(s[i] == '9') t+= "1";
        else t += s[i];
    }
    cout << t << endl;
    return 0;
}
