#include<iostream>
using namespace std;
int main(){
  int h,w; cin >> h >> w;
  int a,b; cin >> a >> b;
  h-= a;
  w-= b;
  cout << h * w ;
}