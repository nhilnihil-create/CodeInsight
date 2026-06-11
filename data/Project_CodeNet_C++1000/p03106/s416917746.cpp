 #include <bits/stdc++.h>
using namespace std;

int main() {
 int a, b, k; cin >> a >> b >> k;
  int count = 0;
  int div;
  if(a>=b) div = b;
  else div = a;
  for(int i = div; count < k; i--){
    if(a%i ==0 && b%i == 0) count++;
    div = i;
  }
  cout << div << endl;
}
