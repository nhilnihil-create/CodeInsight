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
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int cnt=0;
    rep(i,a+1){
        if(i*500>x) break;
        rep(j,b+1){
            if(i*500+j*100>x) break;
            rep(k,c+1){
                if(i*500+j*100+k*50>x) break;
                if(i*500+j*100+k*50==x) cnt++;
            }
        }
    }
    cout<<cnt;
}