#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int r, g, b, n;
    cin>>r>>g>>b>>n;
    int ans = 0;
    rep(i, 3001){
        rep(j, 3001){
            int k = n-(r*i+g*j);
            if(k%b == 0 && k>=0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}