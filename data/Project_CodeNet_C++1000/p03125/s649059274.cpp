#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi= vector<int>;
using vvi= vector<vi>;
using vd= vector<double>;
using vvd= vector<vd>;
using vc= vector<char>;
using vb= vector<bool>;
#define rep(i,x,n) for(int i=x; i<n; i++)
#define all(x) x.begin(), x.end()


int main(){
  int a,b;
  cin >> a >> b;

  if(b%a){
    cout << b-a;
  }else{
    cout << a+b;
  }
}
