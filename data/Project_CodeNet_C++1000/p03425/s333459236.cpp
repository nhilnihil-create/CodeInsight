#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  map<char,long long> A;
  for(long long i=0;i<N;i++){
    string S;
    cin>>S;
    A[S[0]]++;
  }
  vector<string> B={"MAR","MAC","MAH","MRC","MRH","MCH","ARC","ARH","ACH","RCH"};
  long long j=0;
  for(string s:B)
    j+=A[s[0]]*A[s[1]]*A[s[2]];
  cout<<j<<endl;
}