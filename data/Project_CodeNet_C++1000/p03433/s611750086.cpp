#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int s=n%500;
  if(s<=k){printf("Yes\n");return 0;}
  printf("No\n");
}