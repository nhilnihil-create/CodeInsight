#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<int64_t>A(X);
  for(int i=0;i<X;i++)
    cin>>A.at(i);
   vector<int64_t>B(Y);
  for(int i=0;i<Y;i++)
    cin>>B.at(i);
   vector<int64_t>C(Z);
  for(int i=0;i<Z;i++)
    cin>>C.at(i);sort(A.begin(),A.end());sort(B.begin(),B.end());
  sort(C.begin(),C.end());reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());reverse(C.begin(),C.end());
  vector<int64_t>D;
  for(int i=1;i<=X;i++)
    for(int j=1;j<=min(K/i,Y);j++)
      for(int k=1;k<=min((K/i)/j,Z);k++)
        D.push_back(A[i-1]+B[j-1]+C[k-1]);
  sort(D.begin(),D.end());reverse(D.begin(),D.end());
  for(int i=0;i<K;i++)
    cout<<D[i]<<endl;
    return 0;
}