#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

//	vector<int> a(n);

  int n,x,cnt=0;
  int sum=0,min=1000;

  cin >> n >> x;
 
  vector<int> m(n);

  for(int i=0;i<n;i++){
    cin >> m[i];
  }

  for(int i=0;i<n;i++){
    sum = sum + m[i];
    if(min > m[i]){
      min = m[i];
    }
  }

//  cout << min << endl;

  x = x - sum;
  cnt = cnt + n;

  cnt = cnt + x/min;

  cout << cnt << endl;

/*  cout << n << " " << x << endl;

  for(int i=0;i<n;i++){
    cout <<  m[i] << " ";
  }
  cout << endl;
*/
}