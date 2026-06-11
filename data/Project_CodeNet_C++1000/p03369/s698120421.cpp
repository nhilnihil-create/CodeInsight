#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    string s;
    cin >> s;
    int m = 700;
    rep(i,3) if(s[i] == 'o') m += 100;
    cout << m << endl;
}