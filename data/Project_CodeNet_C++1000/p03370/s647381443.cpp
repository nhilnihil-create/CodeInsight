#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,X,count=0,sum=0;
  cin >> N >> X;
  vector<int> M(N);
  for(int i=0;i<N;i++){
    cin >> M.at(i);
    sum+=M.at(i);
    count++;
  }
  sort(M.begin(),M.end());
  while(sum+M.at(0)<=X){
    sum+=M.at(0);
    count++;
  }
  cout << count << endl;
}
  