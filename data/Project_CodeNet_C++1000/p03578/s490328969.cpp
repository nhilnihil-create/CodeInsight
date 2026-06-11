#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>d(n);
  rep(i,n){
    cin>>d.at(i);
  }
  sort(d.begin(),d.end());
  queue<int>q;
  rep(i,n){
    q.push(d.at(i));
  }
  int m;
  cin>>m;
  vector<int>t(m);
  rep(i,m){
    cin>>t.at(i);
  }
  sort(t.begin(),t.end());
  int i=0;
  while(!q.empty()&&i<m){
    int c=q.front();
    if(t.at(i)==c){
      i++;
    }
    q.pop();
  }
  
  if(i==m){
    cout<<"YES"<<endl;
  }
  
  else{
    cout<<"NO"<<endl;  
  }
  
}