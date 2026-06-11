#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 100000000



int main(){
    int a,b,c,x;
    cin>>a>>b>>c>>x;

    int ans = 0;
    for(int i=a; i>=0; --i){
        for(int j=b; j>=0; --j){
            for(int k=c; k>=0; --k){
                int temp = i*500 + j*100 + k*50;
                if(temp == x) ++ans;
                else if(temp < x) break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}