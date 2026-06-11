#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,y,x;
  cin >> n >> y;
  y /= 1000;
  for(x=0;x<=n;x++){
    if((y-n-x*9)%4==0&&y-n-x*9>=0&&5*n-y+5*x>=0){
      cout << x << ' ' << (y-n-x*9)/4 << ' ' << (5*n-y+5*x)/4 << endl;
      return 0;
    }
  }
  
  cout << "-1 -1 -1" << endl;
}