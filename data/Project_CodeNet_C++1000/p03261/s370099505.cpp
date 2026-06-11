#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i,n)cin >> w.at(i);
    bool flag=true;
    rep(i,n-1){
        if(w.at(i).at(w.at(i).size()-1)!=w.at(i+1).at(0)) flag=false;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(w.at(i)==w.at(j))flag=false;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}