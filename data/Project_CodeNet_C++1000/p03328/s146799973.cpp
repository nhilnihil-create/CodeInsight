#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  int x=b-a;
  int h=x*(x+1)/2;
  int ans=h-b;
  cout<<ans<<endl;
}
