#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  for(int &x:A) cin>>x;
  vector<int> num(N);
  for(int i=0;i<N;i++)
    num[A[i]-1]++;
  sort(num.begin(),num.end());
  reverse(num.begin(),num.end());
  int sum=0;
  for(int i=0;i<K&&num[i]!=0;i++) sum+=num[i];
  cout<<N-sum<<endl;
}
  
    
    