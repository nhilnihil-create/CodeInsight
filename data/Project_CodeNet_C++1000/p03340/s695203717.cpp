#include<iostream>
using namespace std;
int N_MAX=200000;
typedef long long ll;
int main()
{
  int n,i,j,x=0,s=0;
  int a[N_MAX];
  ll res=0;
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=0,j=0;i<n;i++){
    for(;j<n;j++){
      if(x!=s)
        break;
      x^=a[j];
      s+=a[j];
    }
    if(x==s)
      j=n+1;
    res+=j-i-1;
    x^=a[i];
    s-=a[i];
  }
  cout << res << endl;
  return 0;
}