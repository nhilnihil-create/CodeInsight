#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    int n,y;
    cin>>n>>y;
    rep(i,n+1){
        rep(j,n+1){
            int k=y-(i*5000+j*1000);
            if(k<0) break;
            if(i+j+k/10000==n&&k%10000==0){
                cout<<k/10000<<" "<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1;
}