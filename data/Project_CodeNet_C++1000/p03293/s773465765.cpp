#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

string rt(string s){
  string n = s.substr(s.length()-1);
  n.append(s, 0, s.length()-1); 
  return n;
}
 
int main(){
  string s, t;
  cin >> s >> t;
  for(int i=0; i<=s.length(); i++){
    if(s==t){
      cout << "Yes" << endl;
      return 0;
    }
    s = rt(s);
  }
  cout << "No" << endl;
  return 0;
}
