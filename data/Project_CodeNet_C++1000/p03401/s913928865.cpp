#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+2);
  A.at(0)=0;
  A.at(N+1)=0;
  int64_t sum=0;
  for(int i=1;i<=N;i++){
    cin >> A.at(i);
    sum+=abs(A.at(i)-A.at(i-1));
  }
  sum+=abs(A.at(N)-A.at(N+1));
  vector<int64_t> ans;
  for(int i=1;i<=N;i++){
    ans.push_back(sum-abs(A.at(i)-A.at(i-1))-abs(A.at(i+1)-A.at(i))+abs(A.at(i+1)-A.at(i-1)));
  }
  for(int i=0;i<ans.size();i++){
    cout << ans.at(i) << endl;
  }
  return 0;
}
