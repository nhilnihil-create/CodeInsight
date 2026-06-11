  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    int N;
    cin >> N;
    string hasY = "n";
    for (int i = 0; i < N; i++) {
      string color;
      cin >> color;
      if (color == "Y") {
        hasY = "y";
      }
    }
    if (hasY == "y") {
      cout << "Four";
    } else {
      cout << "Three";
    }
  }
      
    
