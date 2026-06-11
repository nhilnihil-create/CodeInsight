#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    bool isOK = true;
    if(s[0] != 'A') isOK = false;
    int cnt = 0;
    for(int i = 2; i < s.size()-1; i++){
        if(s[i] == 'C')cnt++;
    }
    if(cnt != 1) isOK = false;
    cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') cnt++;
    }
    if(cnt + 2 != s.size()) isOK = false;
    if(isOK) cout << "AC" << endl;
    else cout << "WA" << endl;
}