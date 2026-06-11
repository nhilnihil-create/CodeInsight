#include <bits/stdc++.h>
using namespace std;

int main() {
int N, x;
cin >> N >> x;
vector<int>a(N);
for(int &x : a)
{
  cin >> x;
}
int64_t sum = accumulate(a.begin(), a.end(), 0LL);
if(x==sum) cout << N << endl;
if(x>sum) cout << N-1 << endl;
if(x<sum)
{
  sort(a.begin(), a.end());
  int cnt=0;
  for (int i = 0; i < N; i++)
  {
    x-=a[i];
    if(x<0) break;
    cnt++;
  }
  
  cout << cnt << endl;
}

  return 0;
}