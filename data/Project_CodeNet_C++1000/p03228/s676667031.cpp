#include<bits/stdc++.h>                                                                                               
 
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr int LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    int a,b,k;
    cin >> a >> b >> k;
    rep(i,k){
        if(i % 2 == 0){ 
            if(a % 2 == 1){ 
                a--;
                a /= 2;
                b += a;
            }
            else{
                a /= 2;
                b += a;
            }
        }
        else{
            if(b % 2 == 1){ 
                b--;
                b /= 2;
                a += b;
            }
            else{
                b /= 2;
                a += b;
            }
        }
    }   
    cout << a << ' ' << b << '\n';
    return 0;
}
