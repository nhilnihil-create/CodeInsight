#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> l(q), r(q);
  for(int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
  }
  
  vector<int> count(n+1, 0);
  for(int i = 1; i < n; i++){
    if(s[i-1] == 'A' && s[i] == 'C'){
      count[i+1] = count[i] + 1;
    }
    else{
      count[i+1] = count[i];
    }
  }	//累積和の考え方
  
  vector<int> answer(q, 0);
  
  for(int i = 0; i < q; i++){
    if(l[i] == 1){
      answer[i] = count[r[i]];
    }
    else{
      if(s[l[i]-2] == 'A' && s[l[i]-1] == 'C'){
        answer[i] = count[r[i]] - count[l[i]-1] - 1;
      }
      else{
        answer[i] = count[r[i]] - count[l[i]-1];
      }
    } 
  }
  
  for(int i = 0; i < q; i++){
    cout << answer[i] << endl;
  }
} 