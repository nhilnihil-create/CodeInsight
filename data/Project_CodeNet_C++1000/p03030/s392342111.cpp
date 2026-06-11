#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  vector<tuple<string, int, int >>vec(N);
  string s;
  int a;
  for (int i=0; i < N; i++){
  cin >> s >> a;
    vec.at(i) = make_tuple(s, a*(-1) , i+1 );
  }
  
  sort(vec.begin(), vec.end());
 
  for (int i=0; i < N; i++){
   tie (s,ignore,a) = vec.at(i);
    cout << a << endl;
 }
 return 0;
}