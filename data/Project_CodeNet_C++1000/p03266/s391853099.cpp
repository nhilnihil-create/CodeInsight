#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int n,k,i;
  vector<int> x(200010);
  cin >> n >> k;
  for(i=1;i<=n;i++){
    x[i]=i%k;
  }
  int zero=0,same=0;
  for(i=1;i<=n;i++){
    if(x[i]==0){
      zero++;
    }
    else if(k/2==x[i]){
      same++;
    }
  }
  if(k%2==1){
    cout << (ll)pow(zero,3) << endl;
  }
  else{
    cout << (ll)pow(zero,3)+(ll)pow(same,3) << endl;
  }
}