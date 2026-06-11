#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N; cin >> N;
  string A,B,C; cin >> A >> B >> C;
  int c = 0;
  for(int i = 0; i < N; i++){
    vector<int> cnt(26,0);
    cnt[A[i]-'a']++; cnt[B[i]-'a']++; cnt[C[i]-'a']++;
    
    char w = A[i];
    for(int j = 0; j < 26; j++){ 
      if(cnt[j] >= 2){  w = (char)(j+'a'); break;}}
    
    if(w!=A[i]){ c++;} if(w!= B[i]){ c++;} if( w!= C[i]){ c++;}
  }
  
  cout << c << endl; return 0;}