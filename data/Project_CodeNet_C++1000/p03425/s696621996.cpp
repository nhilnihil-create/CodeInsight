#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll c[5];

int main(){
   int n;
   cin>>n;
   rep(i,n){
       string s;
       cin>>s;
       if(s[0]=='M') c[0]++;
       else if(s[0]=='A') c[1]++;
       else if(s[0]=='R') c[2]++;
       else if(s[0]=='C') c[3]++;
       else if(s[0]=='H') c[4]++;
   } 

   ll ans=0;
   for(int i=0;i<5;i++){
       for(int j=i+1;j<5;j++){
           for(int k=j+1;k<5;k++){
               ans+=c[i]*c[j]*c[k];
           }
       }
    }

    cout<<ans<<endl;
}