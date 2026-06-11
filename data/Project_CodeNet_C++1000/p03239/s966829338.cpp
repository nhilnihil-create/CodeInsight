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
    int n,T;
    cin>>n>>T;
    int c,t;
    int tcnt=0,cost=10000;
    rep(i,n){
        cin>>c>>t;
        if(t<=T){
            tcnt++;
            cost=min(cost,c);
        }
    }
    if(tcnt==0) cout<<"TLE";
    else cout<<cost;
}