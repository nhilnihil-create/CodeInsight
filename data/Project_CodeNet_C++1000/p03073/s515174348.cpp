#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    string s, a = "", b = "";
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i % 2) a += '1';
        else a += '0';
    }
    for(int i = 0; i < s.size(); i++){
        if(i % 2) b += '0';
        else b += '1';
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] != a[i]) ans1 ++;
    for(int i = 0; i < s.size(); i++)
        if(s[i] != b[i]) ans2 ++;
    cout << min(ans1, ans2);
    return 0;
}
