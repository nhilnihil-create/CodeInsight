#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<bitset<10>> F(N);
  for(bitset<10> &i:F)
    for(int j=0;j<10;j++){
      int k;
      cin>>k;
      i[j]=k;
    }
  vector<vector<int>> P(N,vector<int>(11));
  for(vector<int> &i:P)
    for(int &j:i)
      cin>>j;
  int k=-1000000000;
  for(int tmp=1;tmp<(1<<10);tmp++){
    bitset<10> S(tmp);
    int j=0;
    for(int i=0;i<N;i++)
      j+=P[i][(S&F[i]).count()];
    k=max(k,j);
  }
  cout<<k<<endl;
}