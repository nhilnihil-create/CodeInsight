#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  for(int i=n; i<=999; i++){
    string s = to_string(i);
    if(s[0]==s[1] && s[1]==s[2]){
      cout << s << endl;
      return 0;
    }
  }
  cout << endl;
  return 0;
}
