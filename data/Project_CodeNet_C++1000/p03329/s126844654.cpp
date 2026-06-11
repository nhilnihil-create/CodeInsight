#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >coins;
  coins.push_back(1);
  int push=1;
  for(int i=1;i<=6;i++){push*=6;coins.push_back(push);}
  push=1;
  for(int i=1;i<=5;i++){push*=9;coins.push_back(push);}
	vector<int >mini(n+1,10000000);
  mini[0]=0;
  for(int i=1;i<=n;i++)
    for(int j=0;j<coins.size();j++)
      if(i-coins[j] >=0 )mini[i] = min(mini[i],mini[i-coins[j]]+1);
  cout<<mini[n];
}