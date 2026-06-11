#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  vector<long long int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans =0;
  for(int i=0;i<n;i++)
    while(!(arr[i]%2))
    {ans++;arr[i]/=2;}
  cout<<ans<<endl;
}