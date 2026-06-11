#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 200000;
int main()
{
  int n,k,a,i,res=0;
  int c[N_MAX];
  cin >> n >> k;
  fill(c,c+n,0);
  for(i=0;i<n;i++){
    cin >> a;
    c[a-1]++;
  }
  sort(c,c+n,greater<int>());
  for(i=0;i<k;i++)
    res+=c[i];
  res=n-res;
  cout << res << endl;
  return 0;
}