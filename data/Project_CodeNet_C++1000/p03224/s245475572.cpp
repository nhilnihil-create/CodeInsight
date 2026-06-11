#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
const ll MOD = 1e9;

int main(){
  ll n;
  cin>>n;
  if(n==1){
	cout<<"Yes"<<endl;
	cout<<2<<endl;
	cout<<1<<" "<<1<<endl;
	cout<<1<<" "<<1<<endl;
	return 0;
  }
  ll f=0;
  ll k;
  for(int i=0;i<n;i++){
	if(i*(i+1)==n*2){
	  f=1;
	  k=i;
	}
  }
  if(f==0){
	cout<<"No"<<endl;
	return 0;
  }
  cout<<"Yes"<<endl;
  cout<<k+1<<endl;
  ll cnt=1;
  vector<ll> v[1111];
  for(int i=1;i<=k;i++){
	v[1].push_back(i);
	cnt++;
  }
  for(int i=2;i<=k;i++){
	v[i].push_back(i);
	for(int j=2;j<i;j++){
	  v[i].push_back(v[j][i-2]);
	}
	ll r=k-v[i].size();
	for(int j=0;j<r;j++){
	  v[i].push_back(cnt);
	  cnt++;
	}
  }
  //  cout<<"A"<<endl;
  for(int i=1;i<=k;i++){
	cout<<k;
	for(int j=0;j<v[i].size();j++){
	  cout<<" "<<v[i][j];
	}
	cout<<endl;
  }
  cout<<k<<" "<<1;
  for(int i=2;i<=k;i++){
	cout<<" "<<v[i][k-1];
  }
  cout<<endl;
  return 0;
}
