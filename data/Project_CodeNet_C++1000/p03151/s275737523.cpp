#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)  cin >> A.at(i);
  vector<int> B(N);
  for(int i=0;i<N;i++)  cin >> B.at(i);

  vector<long long> AB(N);
  for(int i=0;i<N;i++)  AB.at(i)=A.at(i)-B.at(i);
  sort(AB.begin(),AB.end());
  long long sum=0;
  for(int i=0;i<N;i++)  sum+=AB.at(i);
  if(sum<0){
    cout << -1 << endl;
    return 0;
  }

  int ans=0;
  sum=0;
  for(int i=0;i<N;i++){
    if(AB.at(i)>=0) break;
    sum+=AB.at(i);
    ans++;
  }
  for(int i=N-1;i>=0;i--){
    if(sum>=0)  break;
    sum+=AB.at(i);
    ans++;
  }
  cout << ans << endl;

  return 0;
}