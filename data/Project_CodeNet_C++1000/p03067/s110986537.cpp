#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<(max({a,b,c})!=c&&min({a,b,c})!=c?"Yes":"No");}