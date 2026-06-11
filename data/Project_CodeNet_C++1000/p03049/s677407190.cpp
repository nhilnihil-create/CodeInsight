#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<string> S(10010);

  cin >> N; int ans = 0;

  int A = 0, B = 0, BA = 0;
  for(int i=0; i<N; i++){
    cin >> S[i]; int l = S[i].length();
    for(int j=0; j<l-1; j++){
      if(S[i][j] == 'A' && S[i][j+1] == 'B') ans++;
    }

    if(S[i][0] == 'B' && S[i][l-1] == 'A'){
      BA++;
    } else if (S[i][0] == 'B'){
      B++;
    } else if (S[i][l-1] == 'A'){
      A++;
    }
  } 

  if(BA >= 1){
    ans += BA-1;
    if(A>0){ans++; A--;}
    if(B>0){ans++; B--;}
  }
  ans += min(A,B);
  cout << ans << endl;
}