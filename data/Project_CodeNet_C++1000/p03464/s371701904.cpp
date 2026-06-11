#include<iostream>
#include<cmath>
using namespace std;
int N_MAX = 100000;
int main()
{
  int k,i;
  long long ma=2,mi=2,t;
  long long a[N_MAX];
  cin >> k;
  for(i=0;i<k;i++)
    cin >> a[i];
  for(i=k-1;i>=0;i--){
    t=ma/a[i];
    if(t*a[i]<mi){
      cout << "-1" << endl;
      return 0;
    }
    ma=(t+1)*a[i]-1;
    mi=(long long)ceil((double)mi/a[i])*a[i];
  }
  cout << mi << " " << ma << endl;
  return 0;
}