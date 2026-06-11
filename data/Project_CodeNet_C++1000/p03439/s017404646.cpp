#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,l,r,mid,k,al,ar;
  string s;
  
  cin >> n;
  
  cout << 0 << endl;
  cin >> s;
  if (s=="Vacant") return 0;
  if (s=="Male") al=ar=0;
  else al=ar=1;
  
  l=0;
  r=n;
  while (r-l>1){
    mid=(l+r)/2;
    cout << mid << endl;
    cin >> s;
    if (s=="Vacant") return 0;
    if (s=="Male") k=0;
    else k=1;
    
    if ((al+k+mid-l)%2==1){
      r=mid;
      ar=k;
    }else{
      l=mid;
      al=k;
    }
  }
  
  cout << l << endl;
  cin >> s;
  if (s=="Vacant") return 0;
  
  return 0;
}