#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t A;
  int64_t ans=0;
  int64_t sum=0;
  map<int64_t,int> m;
  for(int i=0;i<N;i++){
    cin >> A;
    sum+=A;
    if(sum==0){
      ans++;
    }
    if(m.count(sum)){
      ans+=m.at(sum);
      m.at(sum)++;
    }else{
      m[sum]=1;
    }
  }
  cout << ans << endl;
  return 0;
}
