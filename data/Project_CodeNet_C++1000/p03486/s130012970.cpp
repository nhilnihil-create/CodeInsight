#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  string s, t, ans;
  cin >> s >> t;
  vector<int> a, b;
  for(int i=0; i<int(s.length()); i++){
    a.push_back(s[i]-'a');
  }
  for(int i=0; i<int(t.length()); i++){
    b.push_back(t[i]-'a');
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  int i=0;
  while(true){
    if(i>=int(b.size())){
      ans = "No";
      break;
    }else if(i>=int(a.size())){
      ans = "Yes";
      break;
    }else if(a[i]==b[i]){
      i++;
      continue;
    }else if(a[i]>b[i]){
      ans = "No";
      break;
    }else if(a[i]<b[i]){
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
