#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)
#define INF (1<<18)


int main() {
    string s;
    cin>>s;

    bool flag = true;
    
    if(s[0] != 'A') flag = false;

    int cnt = 0;
    int index = -1;
    rep2(i,2,s.length()-1){
        if(s[i]=='C'){
            index = i;
            cnt++;
        }
    }
    if(cnt != 1) flag = false;

    rep(i,s.length()){
        if(i == 0 || i == index) continue;
        else if(!(s[i] >= 'a' && s[i] <='z')) flag = false;
    }

    cout<< ( flag ? "AC" : "WA") <<endl;

    return 0;
}
