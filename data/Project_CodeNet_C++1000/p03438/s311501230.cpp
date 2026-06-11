#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  vector<ll> av,vm;
  priority_queue<ll> pque;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    av.push_back(a);
  }
  ll cnt=0,mcnt=0,one=0;
  for(int i=0;i<n;i++){
    ll b;
    cin>>b;
    if(b-av[i]>1) pque.push(b-av[i]);
    else if(b-av[i]==1) one++;
    else mcnt+=av[i]-b;
    cnt+=b-av[i];
  }
  if(cnt<mcnt){
    cout<<"No"<<endl;
    return 0;
  }
  while(mcnt>0){
    if(pque.empty()){
      cout<<"No"<<endl;
      return 0;
    }
    ll an=pque.top();
    pque.pop();
    mcnt-=min(mcnt,an/2);
  }
  cout<<"Yes"<<endl;
}
