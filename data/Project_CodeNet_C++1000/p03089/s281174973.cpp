#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  int n;
  stack<int> q;
  cin >> n;
  vector<int> v(n);
  r(i,n)cin >> v[i];
  while(n){
    bool flag=true;
    for(int i = n-1; i>=0; i--){
      if(v[i]==i+1){
        q.push(v[i]);
        v.erase(v.begin()+i);
        n--;
        flag=false;
        break;
      }
    }
    if(flag)break;
  }
  if(!n){
    while(!q.empty()){
      cout<<q.top()<<endl;
      q.pop();
    }
  }
  else cout<<-1<<endl;
}
