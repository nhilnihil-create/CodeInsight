#include <bits/stdc++.h>
using namespace std;

int main() {
  char a[3];
  int count = 0;
  int i;
  cin >> a[0];
  cin >> a[1];
  cin >> a[2];
  for(i = 0;i < 3;i++){
  	if(a[i] == '1'){
    	count++;
    }
  }
  cout <<  count << endl;
}