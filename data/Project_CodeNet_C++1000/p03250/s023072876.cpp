#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
  int a[3];
  
    cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);

  cout << a[2]*10+a[1]+a[0] << endl;
}
