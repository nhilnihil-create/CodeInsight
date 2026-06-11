#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,b=2,p=2,ans=0;
    cin >> n;
    
    if(n==1){
        cout << 1;
        return 0;
    }
    
    while(1){
        while(1){
            if(pow(b,p)<=n)ans=max(ans,(int)pow(b,p));
            if(pow(b,p)>n) break;
            p++;
        }
        b++;p=2;
        if(pow(b,p)>n)break;
    }
    
    cout << ans;
    
    return 0;
}