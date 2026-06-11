#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  double A=0;
  cin>>N;
  for(int i=0;i<N;i++){
    double x=0;
    string u;
    cin>>x>>u;
    if(u=="JPY")A+=x;
    else A+=x*380000.000;
  }
  cout<<A<<endl;
}
