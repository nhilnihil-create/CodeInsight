    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      int c1, c2, c3, c4;

      cin >> N;
      
      c1 = N / 1000;
      c2 = N / 100 % 10;
      c3 = N / 10 % 10;
      c4 = N % 10;
      
      if (c1 == c2 && c1 == c3)
      {
        cout << "Yes" << endl;
      }
      else if (c2 == c3 && c2 == c4)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }