#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,a,b,c,d=0,e=0,f=0;
  cin >> n >> a >> b;
  r(i,n){
    cin >> c;
    if(c<=a)d++;
    else if(a<c&&c<=b)e++;
    else f++;
  }
  cout << min(d,min(e,f))<<endl;
}