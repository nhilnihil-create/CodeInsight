#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    string s; cin >> s;
    int n=s.size();
    vector<bool> p(n,0);
    vector<char> c={'A','C','G','T'};
    rep(i,n){
        rep(j,4){
            if(s[i]==c[j]){
                p[i]=1;
            }
            if(p[i]==1) continue;
        }
    }

    int ans=0;
    int now=0;
    rep(i,n){
        if(p[i]) now++;
        else now=0;
        ans=max(now,ans);
    }
    cout << ans << endl;
}