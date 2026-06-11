#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c, i, ans;
  int arr[3];
  for(i=0; i<3; i++)
  cin>>arr[i];
  sort(arr, arr+3);  
  ans = abs(arr[0]-arr[1]) + abs(arr[1]-arr[2]);
  
  cout<<ans<<endl;
  return 0;
}
