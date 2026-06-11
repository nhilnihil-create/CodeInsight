#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,K;
  char S[100];
  string J;
  cin>>N>>K;
  cin>>S;
   int index = K -1;
 	S[index] = S[index] + 32;
   cout<<S;
   return 0;
}