
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
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
#define MOD 1000000007

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);
 }

 long long numbers[500005];


 int main(){

  long long n,Y;
  cin>>n>>Y;

  for(int x=0;x<=n;x++)
  {
      for(int y=0;y<=n;y++)
      {
         if(10000*x+5000*y+1000*(n-x-y) == Y && n-x-y>=0){
            cout<<x<<" "<<y<<" "<<n-x-y<<endl;
         return 0; }
      }
  }

  cout<<"-1 -1 -1"<<endl;

return 0;
 }