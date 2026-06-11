#include <bits/stdc++.h>
using namespace std;

int sum_place(int n){
  string s=to_string(n);
  int sum=0;
  for(int i=0;i<s.size();i++){
    sum+=s.at(i)-'0';
  }
  return sum;
}

int main(){
  int N;
  cin >> N;
  int A,B;
  int ans=1e9;
  for(A=1;A<=N/2;A++){
    B=N-A;
    ans=min(ans, sum_place(A)+sum_place(B));
  }
  cout << ans << endl;
  return 0;
}
