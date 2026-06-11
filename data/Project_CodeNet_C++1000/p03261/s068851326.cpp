#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    string tmp;
    rep(i, n){
        cin >> w[i];
        //w.push_back(tmp);
    }

    bool flg = true;
    repa(i, 1, n){
        if(w[i-1].back() != w[i].front()) flg = false;
        rep(j, i){
            if(w[i] == w[j]) flg = false;
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}