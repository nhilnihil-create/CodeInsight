#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  cout << 0 << endl;
  int l = 0, r = n-1;
  vector<string> seet(n);
  string start;
  cin >> start;
  if(start == "Vacant") return 0;
  for(int i = 0; i < 20; i++){
    int next = (l + r + 1) / 2;
    cout << next << endl;
    string s;
    cin >> s;
    if(s == "Vacant") return 0;
    bool ok = true;
    if(s == start && next%2) ok = false;
    if(s != start && next%2 == 0) ok = false;
    if(ok) l = next;
    else r = next;
  }
}