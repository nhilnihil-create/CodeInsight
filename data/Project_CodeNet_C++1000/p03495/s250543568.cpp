#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k; cin >> n >> k;
  int d[n+1]; for (int i = 0; i < n; i++) cin >> d[i];
  int num[n] = {0}; for (int i = 0; i < n; i++) num[d[i]-1]++;
  int count1 = 0;
  for (int i = 0; i < n; i++) if(num[i]) count1++;
  
  if (count1 <= k) cout << 0 << endl;
  else{
    sort(num, num + n);
    int count2 = 0;
    for (int i = 0; i < n-k; i++) count2 += num[i];
    cout << count2 << endl;
  }
}
    
      