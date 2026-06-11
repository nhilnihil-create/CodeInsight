#include<bits/stdc++.h>
using namespace std;

int main(){

  long long i, j, k, Sum=0, N;
  cin>>N;
  map<char, long long> S;
  string s;
  vector<char> I={'M', 'A', 'R', 'C', 'H'};
  
  for(i=0; i<N; i++){
    cin>>s;
    S[s[0]]++;
  }
  for(i=0; i<5; i++){
    for(j=i+1; j<5; j++){
      for(k=j+1; k<5; k++){
        Sum+=S[I[i]]*S[I[j]]*S[I[k]];
      }
    }
  }
  cout << Sum << endl;
  return 0;
}