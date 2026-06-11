#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    rep(i,n){
        int cnt=0;
        for(char c='a';c<='z';c++){
            bool left=false,right=false;
            rep(j,i)
                if(s[j]==c) left=true;
            repi(j,i,n)
                if(s[j]==c) right=true;
            if(left&&right) cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}