#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15

 int main(){

 long long n,a,b,ans=0;
 cin>>n>>a>>b;

  for(int i=1;i<=n;i++)
 {
    int sum =0;

    if(i<10) sum = i;
    else{
    int num = i;
    while(num){
        int rem = num%10;
        sum += rem;
        num = num/10;
    }
  }

    if(sum >= a && sum <= b)
        ans += i;
  }

  cout<<ans<<endl;

 return 0;
 }
