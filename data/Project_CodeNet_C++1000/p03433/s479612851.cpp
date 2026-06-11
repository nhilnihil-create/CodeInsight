    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int cost, one_yen, mod=0, sum=0;

      cin >> cost >> one_yen;
      mod = cost / 500;
      sum = cost - mod * 500;
      
      if((one_yen - sum) >= 0 ) {
      	cout << "Yes" << endl;
      } else {
          cout << "No" << endl;
      }
    }