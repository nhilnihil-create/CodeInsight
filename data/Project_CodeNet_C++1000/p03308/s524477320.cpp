#include <iostream>
using namespace std;

int main() {
  int n,mn=1e9+1,mx=0;
  cin>>n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin>>a;
    mn=min(mn,a);
    mx=max(mx,a);
  }
  cout<<mx-mn<<endl;
}
