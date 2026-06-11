#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
    ll n;cin >> n;
    int d = 3600;
    rep(a,d)rep(b,d){
        if(ll(4*a*b)-n*(a+b) > 0){
            //printf("%d %d \n",a,b);
            if(n*a*b%(ll(4*a*b)-n*(a+b)) == 0){
                printf("%d %d %lld \n",a,b,n*a*b/(ll(4*a*b)-n*(a+b)));
                return 0;
            }
        }
    }
}