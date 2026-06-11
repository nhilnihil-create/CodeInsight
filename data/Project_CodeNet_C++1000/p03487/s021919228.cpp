#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100000;
int main()
{
  int n,t=1,i,res=0;
  int a[N_MAX];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  sort(a,a+n);
  for(i=1;i<n;i++)
    if(a[i]==a[i-1]){
      t++;
    }else{
      if(t>=a[i-1])
        res+=t-a[i-1];
      else
        res+=t;
      t=1;
    }
  if(t>=a[i-1])     
    res+=t-a[i-1];
  else
    res+=t;
  cout << res << endl;
  return 0;
}