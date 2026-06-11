#include <bits/stdc++.h>

typedef long long int ll;
#define pll pair <ll, ll>
#define pii pair <int, int>
#define f first
#define s second
#define pb push_back
#define vll vector <ll> 
#define mll map <ll ,ll> 
#define prtq  priority_queue <long long>
#define rep(a,b) for(i=a;i<b;i++) 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf 1e18
using namespace std;
#define Mod 1000000007
////////////////////////////////////////////////////////////////////

void fio()
{
#ifndef ONLINE_JUDGE
freopen("input1.txt", "r", stdin);
freopen("output1.txt", "w", stdout);
#else
#endif
}

void tim()
{
   #ifndef ONLINE_JUDGE
   cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
   #endif
}

int sumofdigit(ll n){
  ll temp=n; int sum=0;
   while(temp){
      sum+=temp%10;
      temp/=10;
    }
    return sum;
}



int main()
{
  fio();  
   IOS; 
    
  int t=1;
// cin>>t;
  while(t--){
    ll n,s;
    cin>>n;
    vll h(n+1);
    int i;
    rep(1,n+1)cin>>h[i];

    vll dp(n+1,0);

    dp[1]=0; dp[0]=0;
    for(i=2;i<=n;i++){
      if(i==2)dp[i]=dp[i-1]+abs(h[i]-h[i-1]);
     else dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i-2]-h[i]));
    }

    cout<<dp[n];


    
 }

   tim();
    return 0; 
 
}

// //
// 199
// 200
// 500
// 1000

// 112
// 120