#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repl(i,n) for(int64_t i=0;i<(int64_t)(n);i++)
#define MAX_N 10000000 //10^7
#define ll int64_t
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    string s; cin>>s;
    int count=0,n=s.size();
    rep(i,n) {
        if(s[i]=='o') count++;
    }
    if(count+15-n>=8) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}