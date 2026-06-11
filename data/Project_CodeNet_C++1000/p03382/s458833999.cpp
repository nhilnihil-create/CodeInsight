#include<iostream>
#include<vector>
#include<array>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
  int n,i;
  cin >> n;
  vector<int> a(n);
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for(i=0;a[i]*2<a[n-1];i++);
  if(a[n-1]-a[i-1]*2<=a[i]*2-a[n-1]) i--;
  printf("%d %d\n",a[n-1],a[i]);
}