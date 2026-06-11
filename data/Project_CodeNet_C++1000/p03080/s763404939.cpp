#include <iostream>
#include <string>
using namespace std;
 
int main(){
  int n;
  string s;
  cin >> n >> s;
  int red = 0;
  for (int i = 0; i < s.length(); ++i){
    if (s[i] == 'R'){
    	red++;
    }
  }
  if (red > n - red){
  	cout << "Yes";
  } else {
    cout << "No";
  }
}