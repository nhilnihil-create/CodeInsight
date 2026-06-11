#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> B.at(i);
  }
  int64_t sum=0;
  int64_t ans=0;
  vector<int> diff;
  for(int i=0;i<N;i++){
    if(A.at(i)>=B.at(i)){
      diff.push_back(A.at(i)-B.at(i));
    }else{
      sum+=B.at(i)-A.at(i);
      ans++;
    }
  }
  sort(diff.begin(),diff.end(),greater<int>());
  for(int i=0;i<diff.size();i++){
    if(sum<=0){
      break;
    }
    sum-=diff.at(i);
    ans++;
  }
  if(sum>0){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
  return 0;
}
