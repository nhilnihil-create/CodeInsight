#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  string s;
  cin >> s;
  queue<char>que;
  ll S = s.size();
  for(int i=0; i<S; i++){
    if(s[i]=='B' && s[i+1]=='C'){
      que.push('Y');
      i++;
    }
    else que.push(s[i]);
  }
  ll ans=0;
  while(que.size()>0){
    ll counta=0;
    ll sizea=0;
    ll ord=0;
    while(que.front()=='A' || que.front()=='Y'){
      ord++;
      ll x = que.front();
      que.pop();
      if(x=='A'){
        counta+=ord;
        sizea++;
      }
    }
    
    while(que.front()=='B' || que.front()=='C') que.pop();
    
    ll count=0;
    for(int i=0; i<sizea; i++){
      count+=ord-i;
    }
    
    ans+=count-counta;
    
  }
  
  cout << ans << endl;
  
}
  
  
  
