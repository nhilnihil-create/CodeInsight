#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
  cin >> n;
  int a=0, b=0, c=0, d=0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(s[0] == 'B' && s[s.size()-1] == 'A') d++;
    else if(s[0] == 'B') b++;
    else if(s[s.size()-1] == 'A') a++;
    for(int j = 0; j < s.size()-1; j++){
      if(s.substr(j, 2) == "AB") c++;
    }
  }
  if(d == 0) c+=min(a, b);
  else{
    if(a+b == 0) c+=d-1;
    else c+=d+min(a, b);
  }
  cout << c << endl;

  return 0;
}
