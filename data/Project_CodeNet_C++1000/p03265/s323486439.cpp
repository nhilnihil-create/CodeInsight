#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,x,y;
  cin>>a>>b>>x>>y;
 cout<<x-(y-b)<<" "<<y+x-a<<" "<<a-(y-b)<<" "<<b+x-a<<endl;
}