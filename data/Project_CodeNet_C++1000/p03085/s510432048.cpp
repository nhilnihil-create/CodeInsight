#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll  = long long;
using v   = vector<int>;
using P   = pair<int,int>;
using vp  = vector<P>;
using vvp = vector<vp>;

int main(){
    char b;cin>>b;
    string s="ACGT";
    rep(i,4){
        if(b==s[i])cout << s[3-i] << endl;
    }
    return 0;
}
