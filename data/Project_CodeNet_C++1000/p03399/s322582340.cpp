#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d;
  if(a > b){
    e = b;
  }
  else{
    e = a;
  }
  if(c > d){
    f = d;
  }
  else{
    f = c;
  }
  
  cout << e + f << "\n";
}
    
  