#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    set<string> said; vector<char> w; bool flag = true;
    rep(i, n){
        string x; cin >> x; int length = x.size();
        if (i == 0){
            w.push_back(x[length-1]);
            said.insert(x);
        }
        else{
            if (x[0] != w[i-1] || said.count(x)){
                flag = false;
            }
            w.push_back(x[length-1]);
            said.insert(x);
     
        } 
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}   