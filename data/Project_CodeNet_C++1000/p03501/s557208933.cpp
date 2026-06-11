    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int n, a, b;
      int A = 0, B = 0;
      cin >> n >> a >> b;
      A = n * a;
      B = b;
      if (A > B) {
       cout << B << endl; 
      }
      else if (A < B){
        cout << A << endl;
      }
      else {
        cout << B << endl;
      }
    }