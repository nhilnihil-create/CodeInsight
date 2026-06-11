#include <bits/stdc++.h>
using namespace std;

int main(){
 string s,t;
  cin >> s >>t;
  int S, T;
  S= s.size();
  T= t.size();
  
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  
  for(int i=0;i<min(S,T);i++){
   if(s.at(i)==t.at(i))continue;
  else if(s.at(i)<t.at(i)){
    cout << "Yes" <<endl;
    return 0;
  }
  else if(s.at(i)>t.at(i)){
    cout << "No" <<endl;
    return 0;
  }
  }
  
  if(S<T){
    cout << "Yes" <<endl;
  }
  else{
    cout << "No" <<endl;
  }
}
  