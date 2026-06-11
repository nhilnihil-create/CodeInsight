#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int sum=1;
  vector<int> vct(n);
  for(int i=0;i<n;i++) cin >> vct[i];
  sort(vct.begin(),vct.end());
  reverse(vct.begin(),vct.end());
  int A=vct[0];
  for(int i=0;i<n;i++){
   if(vct[i]<A)sum++; A=vct[i];
  }
  cout<<sum<<endl;
  }