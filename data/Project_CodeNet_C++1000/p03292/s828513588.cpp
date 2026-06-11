#include <bits/stdc++.h>
using namespace std;

int main(){

  int a[3];
  for(int i=0; i<3; i++){
	cin >> a[i];
  }
  cout << max(a[0],max(a[1],a[2]))-min(a[0],min(a[1],a[2])) << endl;
}