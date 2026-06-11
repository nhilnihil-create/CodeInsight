#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s,t;
    char u;
    cin >> s >> t;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        u=s.at(s.size()-1);
        for(int j=s.size()-1;j>0;j--)s.at(j)=s.at(j-1);
        s.at(0)=u;
        if(s==t)flag=true;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

}