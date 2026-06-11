#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a=0;
    int b=0;
    rep(i,s.size()){
        if(s.at(i)=='R')a++;
        else b++;
    }
    if(a>b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
