# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define ll long long

ll fpb(ll a, ll b){
  return (b == 0) ? a : fpb(b, a%b);
}

ll kpk(ll a, ll b){
  return a / fpb(a,b) * b;
}

bool valid(string S, string T) {
  ll lenS = S.size(), lenT = T.size();
  ll f = fpb(lenS, lenT);
  for(int i=0; i<f; i++){
    if(S[i * lenS/f] != T[i * lenT/f]) return false;
  }
  return true;
}

int main(){
 
  int lenS, lenT;
  string S, T;
  cin >> lenS >> lenT;
  cin >> S >> T;
  
  if(valid(S, T)) cout << kpk(lenS, lenT) << endl;
  else cout << -1 << endl;
  
  return 0;
} 

