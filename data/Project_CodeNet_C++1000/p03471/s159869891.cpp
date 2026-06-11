#include<iostream>
#define ll long long

using namespace std;

ll n,y;

int main(){
  cin >> n >> y;
  bool f = false;
  for(int a=0;a <= 2000;a++){
    for(int b=0;b <= 2000;b++){
      int c = n - a - b;
      if(y == 10000*a + 5000*b + 1000*c && c >= 0){
        cout << a << " " << b << " " << c << endl;
        f = true;
        break;
      }
    }
    if(f) break;
  }
  if(!f) cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}