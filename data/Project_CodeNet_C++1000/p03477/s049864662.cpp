#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,ans=0;
  cin >> a >> b >> c >> d;
  
  ans = (a+b) - (c+d);
  if(ans == 0){
    cout << "Balanced" << endl;
  }else if(ans > 0){
    cout << "Left" << endl;
  }else{
    cout << "Right" << endl;
  }
}
