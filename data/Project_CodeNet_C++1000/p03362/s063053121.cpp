#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
vector<ll>multiple;

void prime(int v){
  multiple[0]=-1;
  multiple[1]=-1;
  for(int i=2; i<=v; i++){
    if(multiple[i]!=0)continue;
    for(int j=i*2; j<=v; j+=i){
     multiple[j]=i;
    }
  }
  
  
  
  
  
}

int main(){
  ll n;
  cin >> n;
  multiple.resize(55556);
  prime(55555);
  for(int i=2; i<=55555; i++){
    if(n==0)break;
    if(multiple[i]==0 && i%5==1){
      cout << i << " ";
      n--;
    }
  }
  
}
  
  
  
  
