#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    string s;cin >>s;
    if(s[1]==s[2]){
        if(s[0]==s[1]||s[2]==s[3])puts("Yes");
        else puts("No");
    }
    else puts("No");
    return 0;
}
