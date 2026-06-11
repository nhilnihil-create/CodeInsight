 #include<bits/stdc++.h>
 using namespace std;
int main(){
  int R;
  cin >> R;
  string res = "AGC";
  if (R < 1200) {
    res = "ABC";
  }else if (R < 2800) {
    res = "ARC";
  }
    cout << res << "\n";
}
