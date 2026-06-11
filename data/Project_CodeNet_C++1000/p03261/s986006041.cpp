#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  vector<string> s;
  for(int i=0; i<n; i++){
    string a;
    cin >> a;
    s.push_back(a);
    if(i==0) continue;
    if(s[i-1][s[i-1].length()-1]!=a[0]){
      cout << "No" << endl;
      return 0;
    }
    for(int j=0; j<i; j++){
      if(a==s[j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
