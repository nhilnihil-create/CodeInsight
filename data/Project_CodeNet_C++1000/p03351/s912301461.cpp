#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if((c-a<=d&&-d<=c-a)||((c-b<=d&&-d<=c-b)&&(a-b<=d&&-d<=a-b))){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
  cout << endl;
}
