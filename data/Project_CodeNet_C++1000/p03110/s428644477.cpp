#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  double x,s=0;
  string u;
  for(int i=0; i<n; i++){
    cin>>x>>u;
    if(u=="JPY") s+=x;
    else s+=380000*x;
  }
  printf("%-10.5lf\n",s);
}