#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int x; cin >> x;
    int ans=0;
    rep(i,50){
        rep2(j,9){
            int k=i;
            rep(y,j) k*=i;
            if(k>ans && k<=x){
                ans=k;
            }
        }
    }
    cout << ans << endl;
}