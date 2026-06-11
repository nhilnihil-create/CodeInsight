#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
#define R(i,n) for(int i = 1; i<=n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,a=0;
  char c;
 cin >> n;
  r(i,n){
    cin >> c;
    if(c=='R')a++;
  }
  if(a>n-a)cout << "Yes"<<endl;
  else cout << "No"<<endl;
}