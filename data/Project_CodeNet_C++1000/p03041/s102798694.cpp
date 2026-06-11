#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

char change(char a){
    if ('a'<=a && a<='z'){
        return a-0x20;
    }else if('A'<=a && a<='Z'){
        return a+0x20;
    }
    return 0;
}

int main(){
    int n,k;cin>>n>>k;
    string s; cin>>s;
    s[k-1] = change(s[k-1]);
    cout<<s<<endl;
}