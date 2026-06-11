

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
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_a(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define long long ll


int main(){

 ll a,b,c;
 cin>>a>>b>>c;

  int maxi = max(max(a,b),c);

   if((3*maxi-a-b-c)%2 == 0)
    cout<<(3*maxi-a-b-c)/2<<endl;
   else
    cout<<(3*(maxi+1)-a-b-c)/2<<endl;

 return 0;
}