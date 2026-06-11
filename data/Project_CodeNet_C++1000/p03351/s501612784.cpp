#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if((pow(a-c, 2)<=d*d) || ((pow(a-b, 2)<=d*d)&&(pow(b-c, 2)<=d*d))){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
