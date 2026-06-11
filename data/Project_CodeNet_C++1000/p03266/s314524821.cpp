#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
ll N,K;
  cin>>N>>K;
ll ans=0;
ll a=0;
ll count1=0;
ll count2=0;
if(K%2==0){
  a=K/2;
  while(1){
    if(a<=N){count1++;}
    else{break;}
    a=a+K;
  }
}
  

  
a=0;
while(1){
a=a+K;
if(a<=N){
  count2++;
}
else{break;}
}

  
ans=count2*count2*count2+count1*count1*count1;
cout<<ans<<endl;

  
}
