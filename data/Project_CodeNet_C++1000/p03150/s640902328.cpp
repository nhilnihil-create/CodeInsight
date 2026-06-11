#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    string s;
    cin >> s;
    bool ok=false;
    rep(i,s.size()){
        for(int j=0; j<s.size()-i; j++){
            string A = s;
            A.erase(i,j);
            if(A == "keyence") ok = true;
        }
    }
    if(ok) cout << "YES" <<endl;
    else cout << "NO" <<endl;
}