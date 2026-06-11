#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> s(N);
  for(int i=0; i<N; i++)  cin >> s[i];

  int M;
  cin >> M;
  vector<string> t(M);
  for(int i=0; i<M; i++)  cin >> t[i];
  
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
 
  int ans = 0;
  int k = 0;
  for(int i=0; i<N; i++){
    string ss = s[i];
    int count = 1;
    for(int j=i+1; j<N; j++){
      if(ss == s[j]){
      	 count++;
     	 i = j;
      }//if
    }//for
    for(int j=k; j<M; j++){
      if(ss == t[j]){
      	count--;
      	k = j;
      }//if
    }//for
  ans = max(ans, count);
  }//for

  cout << ans << "\n";
}//main
