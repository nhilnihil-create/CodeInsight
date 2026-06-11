#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi= vector<int>;
using vvi= vector<vi>;
using vd= vector<double>;
using vvd= vector<vd>;
using vc= vector<char>;
using vs= vector<string>;
using vb= vector<bool>;
using vl= vector<ll>;
#define rep(i,x,n) for(int i=x; i<n; i++)
#define all(x) x.begin(), x.end()

int main(){
  int r;
  cin >> r;

  if(r<1200){
    cout << "ABC";
  }else if(r<2800){
    cout << "ARC";
  }else{
    cout << "AGC";
  }
  
  return 0;
}
