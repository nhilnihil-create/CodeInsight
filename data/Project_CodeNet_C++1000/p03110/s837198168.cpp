#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
double x;
double yen = 0;
string u;
cin >> n;
for (int i = 0;i < n;i++){
  cin >> x >> u;
  if (u == "JPY"){
    yen += x;
  }
  else{
    yen += 380000*x;
  }
}
cout << fixed << setprecision(10);
cout << yen << endl;
}
