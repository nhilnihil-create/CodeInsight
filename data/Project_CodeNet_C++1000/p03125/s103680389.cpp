 #include<bits/stdc++.h>
 using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int res = b - a;
  if (b % a == 0) {
    res = b + a;
  }

  cout << res << "\n";
}
