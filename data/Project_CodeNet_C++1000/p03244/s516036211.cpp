#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<vector<int>>odd(100001,vector<int>(2));
  for(int i=0;i<n;i+=2) odd[a[i]][0]++;
  vector<vector<int>>even(100001,vector<int>(2));
  for(int i=1;i<n;i+=2) even[a[i]][0]++;
  for(int i=0;i<100001;i++){
    odd[i][1]=i;
    even[i][1]=i;
  }
  sort(odd.begin(),odd.end());
  sort(even.begin(),even.end());
  if(even[100000][1]!=odd[100000][1]) cout<<n-even[100000][0]-odd[100000][0]<<endl;
  else{
    if(even[99999][0]>odd[99999][0]) cout<<n-odd[100000][0]-even[99999][0]<<endl;
    else cout<<n-odd[99999][0]-even[100000][0]<<endl;
  }
}