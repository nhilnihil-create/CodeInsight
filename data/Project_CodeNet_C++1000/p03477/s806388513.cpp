#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,D;
cin >> A >> B >> C >> D;
  int x=A+B;
  int y=C+D;
if(x>y){
cout << "Left";
}
else if(x<y){
cout << "Right";
}
else{
cout << "Balanced";
}
}