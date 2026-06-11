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
    int a,amari=9,time=0,zero=0;
    rep(i,5){
        cin>>a;
        if(a%10==0){
            zero++;
            time+=a;
        }else{
            amari=min(amari,a%10);
            time+=a/10*10+10;
        }
    }
    if(zero==5) cout<<time;
    else cout<<time+amari-10;
}