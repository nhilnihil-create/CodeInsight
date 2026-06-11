#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ans = 0; 
  int n, arr[100];
  int i;
  
  cin >> n;
  
  for(i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(i = 0; i < n; i++){
    if(i >= 1 && arr[i] == arr[i - 1]){
      ans++;
      arr[i] = arr[i + 1] - 1;
    }
  }
  cout << ans << endl;
}
