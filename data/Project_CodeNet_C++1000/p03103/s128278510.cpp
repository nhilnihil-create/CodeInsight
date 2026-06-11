#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
  cin>>n>>m;
  vector<pair<long long,long long > >shop(n);
  for(int i=0,a,b;i<n;i++){
  	cin>>a>>b;
    shop.push_back(make_pair(a,b));
  }
  sort(shop.begin(),shop.end());
  long long items=m;
  long long money = 0;
  for(int i=0;items>0;i++){
  	money+=shop[i].first*min(items,shop[i].second);
    items-=min(items,shop[i].second);
  }
  cout<<money;
}