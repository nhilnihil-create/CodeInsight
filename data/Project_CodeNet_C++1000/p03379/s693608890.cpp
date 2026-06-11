#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  #define int long long


  int n;
  cin >> n;
  
  int m= n/2;
  
  vector <int> a(n);
  
  rep(i,n)
    cin >> a.at(i);
  
  vector <int> b(n);
    b=a;
  sort(b.begin(),b.end());

  
  rep(i,n){
    if(a.at(i)<=b.at(m-1))
      cout << b.at(m) << endl;
    else
      cout << b.at(m-1) << endl;
  }
  
}