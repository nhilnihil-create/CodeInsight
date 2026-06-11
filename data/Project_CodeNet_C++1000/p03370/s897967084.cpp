#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <set>
#include <math.h>
#define pai 3.14159265358979323846264338327950288;
#define keta(n) cout << fixed << setprecision((n));
using ll = long long;
int main()
{
  int n,x;
  cin>>n>>x;
  int a=1000,sum =0;
  rep(i,n){
    int m;
    cin>>m;
    sum += m;
    a= min(a,m);
  }
  cout<<n+(x-sum)/a;
    
    
}
