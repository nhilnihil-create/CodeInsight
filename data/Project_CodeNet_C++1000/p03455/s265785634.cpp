#include <bits/stdc++.h>

using namespace std;

using intL = long long;

#define MOD_NUMBER 1000000007

template <class T> void vector_print(vector<T> vec) {
  for (unsigned int i = 0; i < vec.size(); i++) {
    cout << vec.at(i);
    if (i < vec.size()-1) {
      cout << " ";
    } else if (i == vec.size()-1) {
      cout << endl;
    }
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  if ((a*b)%2) {
    cout << "Odd" << endl;
  } else {
    cout << "Even" << endl;
  }
  return 0;
}
