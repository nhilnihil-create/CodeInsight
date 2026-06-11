#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
#define prt(var) cout << (var) << endl;
#define rep(i,n) for(int i=0; i<int(n); i++)

int main() {
  int n;
  cin>>n;
  int a[n+1];
  a[0]=-1;
  rep(i,n){
    int k;
    cin>>k;
    a[k]=i+1;
  }
  
  int mx=0;
  int tmp=0;
  rep(i,n){
    if(a[i]<a[i+1]){
      tmp++;
    } else {
      tmp=1;
    }
    
    mx = max(mx, tmp);
  }
  
  prt(n-mx);
}