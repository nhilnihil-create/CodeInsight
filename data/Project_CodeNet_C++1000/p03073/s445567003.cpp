#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    string s;
    cin >> s;
    
    int ansb = 0, answ = 0;
    
    rep(i,s.size()){
        if((s[i]+i)%2)ansb++;
        else answ++;
    }
    
    cout << min(ansb, answ) << endl;
    
    return 0;
}