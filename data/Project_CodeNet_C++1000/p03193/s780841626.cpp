#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,h,w,count=0,a,b;
  cin>>n>>h>>w;
  r(i,n){
    cin >> a >> b;
    if(a>=h&&b>=w)count++;
  }
  cout << count << endl;
}