#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N),B(N);
  int64_t sumA=0;
  int64_t sumB=0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sumA+=A.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> B.at(i);
    sumB+=B.at(i);
  }
  if(sumA<sumB){
    cout << -1 << endl;
    return 0;
  }
  vector<int64_t> diff(N);
  for(int i=0;i<N;i++){
    diff.at(i)=A.at(i)-B.at(i);
  }
  sort(diff.begin(),diff.end());
  if(diff.front()>=0){
    cout << 0 << endl;
    return 0;
  }
  int left=0;
  int right=N-1;
  vector<bool> flag(N,false);
  int64_t ans=0;
  while(diff.at(left)<0){
    if(diff.at(right)+diff.at(left)>0){
      diff.at(right)+=diff.at(left);
      diff.at(left)=0;
      if(!flag.at(left)){
        flag.at(left)=true;
        ans++;
      }
      if(!flag.at(right)){
        flag.at(right)=true;
        ans++;
      }
      left++;
    }else if(diff.at(right)+diff.at(left)<0){
      diff.at(left)+=diff.at(right);
      diff.at(right)=0;
      if(!flag.at(left)){
        flag.at(left)=true;
        ans++;
      }
      if(!flag.at(right)){
        flag.at(right)=true;
        ans++;
      }
      right--;
    }else{
      diff.at(left)=0;
      diff.at(right)=0;
      if(!flag.at(left)){
        flag.at(left)=true;
        ans++;
      }
      if(!flag.at(right)){
        flag.at(right)=true;
        ans++;
      }
      left++;
      right--;
    }
  }
  cout << ans << endl;
  return 0;
}
