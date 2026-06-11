#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int L;
  cin>>L;

  int r=0;
  for(int i=1;;i++){
    if(pow(2,i)<=L) r=i;
    else break;
  }

  int R=pow(2,r);
  int n=r+1;
  int m=2*r;
  vector<int> a,b,c;
  for(int i=1;i<=r;i++){
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(0);
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(pow(2,i-1));
  }

  for(int i=r;i>0;i--){
    if(L-pow(2,i-1)>=R){
      a.push_back(i);
      b.push_back(n);
      c.push_back(L-pow(2,i-1));
      L-=pow(2,i-1);
      m++;
    }
  }

  cout<<n<<" "<<m<<endl;
  for(int i=0;i<m;i++){
    cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
  }

  return 0;
}
