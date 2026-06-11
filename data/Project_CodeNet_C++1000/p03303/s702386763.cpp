#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int w;
    cin >> w;

    int n = s.length();
    int t = 0;
    string ans;
    while(1){
        if(t >= n){
            break;
        }
        ans += s[t];
        t += w;
    }

    cout << ans << endl;
}