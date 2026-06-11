#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;
const lli m = 3500;

int main(void){
    cin >> n;
    for(lli i = 1; i <= m; i++){
        for(lli j = 1; j <= m; j++){
            if(4*m*i*j <= n*(i*j+j*m+m*i)) continue;
            lli l, r, mid;
            l = 1; r = 1e9;
            while(r-l > 1){
                mid = (l+r)/2;
                if(4*mid*i*j >= n*(i*j+j*mid+mid*i)){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            if(4*r*i*j == n*(i*j+j*r+r*i)){
                cout << i << " " << j << " " << r << endl;
                return 0;
            }
        }
    }
    return 0;
}
