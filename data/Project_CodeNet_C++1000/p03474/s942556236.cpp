#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int a,b;
    string s;
    cin >> a >> b >> s;
    bool flag=true;
    int count=0;
    rep(i,s.size()){
        if(s.at(i)=='-') count++;
    }
    if(count!=1) flag=false;
    if(s.at(a)!='-')flag=false;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

}