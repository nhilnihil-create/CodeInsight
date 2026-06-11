#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define F first
#define S second
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

const ll M=1e9+7;
const int MaxM=100005;


void SieveOfEratosthenes(int n)                                   //all prime <= n
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}


bool isPowerOfTwo (int x)
{
    return x && (!(x&(x-1)));
}



bool comp(pair<int,int> a,pair<int,int> b){
  if(a.F==b.F){
    return a.S>b.S;
  }
  return a.F<b.F;
}




void solve(){


int n,k;cin>>n>>k;

bool dp[k+1]={false};
int a[n];
for(int i=0;i<n;i++){
          cin>>a[i];
          dp[a[i]]=true;      
}

for(int i=0;i<=k;i++){
    if(!dp[i]){
        for(int j=0;j<n;j++){

              if(a[j]<i){
                if(!dp[i-a[j]]){dp[i]=true; break;}
              }
              else if(a[j]==i){dp[i]=true; break;}
              else{break;}
        }
    }
      
}


if(dp[k]){cout<<"First";}
else{cout<<"Second";}

}

int main(){


   int t=1;
//  cin>>t;
   while(t--){
      solve();
       }

 }
