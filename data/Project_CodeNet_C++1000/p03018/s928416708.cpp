#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    string s;  cin >> s;
    string t;
    int N = s.length();
    for(int i=0; i<N; i++){
        if(i + 1 < N && s.substr(i, 2) == "BC"){
            t += '$';
            i++;
        }else{
            t += s[i];
        }
    }

    ll ans = 0;
    ll cnt = 0;
    for(char c : t){
        if(c == 'A') cnt++;
        else if(c == '$') ans += cnt;
        else cnt = 0;
    }
    cout << ans << endl;
}