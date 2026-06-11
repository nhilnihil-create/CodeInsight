#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> a(m);
  for(int i=0;i<m;i++) cin >> a[i];

  int cnt = 0;
  for(int i=0;i<m;i++){
    if(x < a[i]){
      cnt++;
    }
  }

  cout << min(cnt,m-cnt) << endl;
}