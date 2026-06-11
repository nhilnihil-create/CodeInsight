#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int N;
  cin>>N;
  vector<ll> data(N);
  for(int i=0;i<N;i++)cin>>data[i];
  sort(data.begin(),data.end());
  cout<<abs(data[0]-data.back())<<endl;
}