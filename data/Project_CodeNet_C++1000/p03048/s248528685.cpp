#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;

    int ans = 0;
    rep(i,3005){
      rep(j,3005){
        if(n - r*i - g*j < 0)
          continue;
        if((n - r*i -g*j) % b == 0)
          ans++;
      }
    }
    cout<<ans<<endl;

}