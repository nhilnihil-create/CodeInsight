
#include <bits/stdc++.h>

using namespace std;

int main()
{
 string S;
 int N,K;
 cin>>N>>K;
 cin>>S;
 int A=K-1;
if(N>=1&&K>=1&&N<=50&&K<=N ){
  if(S.length()==N){
     S[A]=tolower(S[A]);
     cout<<S;
 }
}
    return 0;
}