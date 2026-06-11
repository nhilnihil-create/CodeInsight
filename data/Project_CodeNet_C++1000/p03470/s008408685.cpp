#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,d[110];
  set<int> s;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>d[i];
    s.insert(d[i]);
  }
  cout<<s.size();  
}
