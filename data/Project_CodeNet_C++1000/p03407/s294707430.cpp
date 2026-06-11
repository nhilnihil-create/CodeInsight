#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
int main() {

  uint input_a,input_b,input_c;
  cin >> input_a >> input_b >> input_c;

  //cout << "input:" <<input_a << " " << input_b << " " << input_c << endl;

  if(input_a + input_b >= input_c){
      cout << "Yes" << endl;
  }else{
      cout << "No" << endl;
  }

}