

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

 long long dt,dx,dy,oldx=0,oldy=0,oldt=0;

 int main(){

 long long n,flag=0;
 cin>>n;

  for(int i=0;i<n;i++)
 {
    long long t,x,y;
    cin>>t>>x>>y;

     dt = t-oldt;
     dx = abs(x-oldx);
     dy = abs(y-oldy);

    if(dt >= dx+dy && (dt-dx-dy)%2 == 0){
        oldt = t;
        oldx = x;
        oldy = y;

    }
    else
    {
        flag = 1;
         break;
    }

  }

  if(flag == 1)
  cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;

 return 0;
 }
