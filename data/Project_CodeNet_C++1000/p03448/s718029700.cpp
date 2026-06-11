#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,count;
  cin >> a >> b >> c >> x;
  count = 0;

  for(int i=0; i<=a; i++){
    for(int j=0; j<=b; j++){
      if(500*i+100*j<=x && 500*i+100*j+50*c>=x ) count++;
    }
  }
  cout << count << endl;
}

