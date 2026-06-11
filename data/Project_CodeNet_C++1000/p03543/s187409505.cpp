#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  int n1 = n/10, n2 = n%1000;
  if(n1%111==0 || n2%111==0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
