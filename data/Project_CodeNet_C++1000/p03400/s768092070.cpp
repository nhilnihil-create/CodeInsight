#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d,x;
  cin>>n>>d>>x;
  int ans=x;
  d--;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans+=d/a;
  }
  cout<<ans+n<<endl;
}
