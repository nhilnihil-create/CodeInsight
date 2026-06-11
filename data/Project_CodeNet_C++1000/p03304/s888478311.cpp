#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,m,d;
  cin>>n>>m>>d;
  cout<<fixed<<setprecision(20);
  if (d==0) {
    cout<<(double)(m-1)/n<<endl;
  } else {
    cout<<(m-1)*(n-d)*2.0/(double)(n*n)<<endl;
  }
}