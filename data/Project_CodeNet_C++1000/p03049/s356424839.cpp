#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a=0;
  int b=0;
  int ba=0;
  
  int ans = 0;
  for(int i = 0; i < N; i++){
    string S;
    cin >> S;
    if(S[0] != 'B' && S[S.size()-1] == 'A') a++;
    if(S[0] == 'B' && S[S.size()-1] != 'A') b++;
    if(S[0] == 'B' && S[S.size()-1] == 'A') ba++;
    
    
    for(int i = 0; i < S.size() -1; i++){
      if(S[i] == 'A' && S[i+1] == 'B') ans++;
    } 
  }
  cerr << a << " "<< b << " " << ba << " " << ans << endl;
  if(ba == 0){
    ans += min(a,b);
  } else { 
    if(a + b > 0){
      ans += ba + min(a,b);
    }
    if(a+b==0){
      ans += ba-1;
    }
  }
  
  cout << ans << endl;
}