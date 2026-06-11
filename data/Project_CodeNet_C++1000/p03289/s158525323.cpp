#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    bool a = 1, b = 1, c = 1;
    if(s[0] != 'A')a = 0;
    int cnt = 0;
    for(int i = 2; i < s.length()-1; i++){
        if(s[i] == 'C')cnt++;
    }
    if(cnt == 1)b = 1;
    else b = 0;
    int lcnt = 0;
    for(int i = 0; i < s.length(); i++){
        if((int)s[i]-'a' < 26 && (int)s[i]-'a' >= 0)lcnt++;
    }
    //cout << lcnt << endl;
    if(s.length()-lcnt == 2)c = 1;
    else c = 0;
    if(a && b && c)cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}
