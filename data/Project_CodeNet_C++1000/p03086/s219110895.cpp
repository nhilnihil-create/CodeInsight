#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool check(string s){
    bool other = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') continue;
        else other = true;
    }
    return (other == false);
}
int main(){
    Hello
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j <= s.size(); j++)
            if(check(s.substr(i, j - i))) ans = max(ans, j - i);
    cout << ans;
    return 0;
}
