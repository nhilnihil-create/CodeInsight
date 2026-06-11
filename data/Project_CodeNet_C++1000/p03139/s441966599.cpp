#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b,c;
  cin>>n>>a>>b;
  c=a+b-n;
  if (c<1)c=0;
  

    cout << min(a,b) <<" "<<c<< endl; // 5
}
