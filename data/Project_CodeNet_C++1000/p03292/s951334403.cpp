#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);
  cout<<abs(a[1]-a[0])+abs(a[1]-a[2])<<"\n";
}
