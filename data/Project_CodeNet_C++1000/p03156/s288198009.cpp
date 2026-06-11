#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int N; cin >> N;
  int A,B; cin >> A >> B;
  
  int count[3] = {0};
  int p;
  REP(i,N){
    cin >> p;
    if(p<=A) count[0]++;
    else if(p<=B) count[1]++;
    else count[2]++;
  }
  int r = min(count[0], min(count[1],count[2]) );
  cout << r << "\n";
}