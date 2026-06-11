#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X,sum=0,count=0;
  cin >> N >> X;
  vector<int> M(N);
  for(int i=0;i<N;i++){
    cin >> M.at(i);
    sum+=M.at(i);
    count++;
    }
  sort(M.begin(),M.end());
  int C=X-sum;
  count+=C/M.at(0);
  cout << count << endl;
}