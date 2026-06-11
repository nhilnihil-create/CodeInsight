#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int a,b,c[5]={0};
  for(int i=0; i<3; i++) {
    cin >> a;
    c[a]++;
    cin >> b;
    c[b]++;
  }
  if(c[1]<3&&c[2]<3&&c[3]<3&&c[4]<3) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
