#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> a(n+2);
  for(int i=1;i<n+1;i++){
    cin >> a.at(i);
  }
  a.at(0)=0;
  a.at(n+1)=0;
  int ans=abs(a.at(0));
  for(int i=0;i<n+1;i++){
    ans+=abs(a.at(i+1)-a.at(i));
  }
  for(int i=1;i<n+1;i++){
    int copy=ans;
    copy-=abs(a.at(i)-a.at(i-1))+abs(a.at(i+1)-a.at(i));
    copy+=abs(a.at(i+1)-a.at(i-1));
    cout << copy << endl;
  }
}