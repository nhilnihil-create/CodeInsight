     #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
     int N;
      cin >> N;
      for (int i = 0; i < N; i++){
        string P;
        cin >> P;
        if (P == "Y"){
          cout << "Four" << endl;
          break;
        }
        else if (i == N-1 && P != "Y"){
          cout << "Three" << endl;
          break;
        }
        else continue;
      }
    }