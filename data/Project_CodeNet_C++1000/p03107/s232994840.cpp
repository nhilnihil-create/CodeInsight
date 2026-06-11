#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    string s;
    cin>>s;
    
    vi c(2,0);
    
    rep(i,s.size()){
        c[s[i]-'0']++;
    }
    cout << min(c[0],c[1])*2<<endl;
    return 0;
}