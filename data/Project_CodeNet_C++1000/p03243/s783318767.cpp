#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x=n/111;
  if(n%111==0) cout<<x<<x<<x<<endl;
  else cout<<x+1<<x+1<<x+1<<endl;
}
