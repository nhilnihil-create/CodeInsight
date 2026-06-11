#include <iostream>
using namespace std;
int main() {
  int n_cats, n_cats_or_dogs, x;
  cin >> n_cats >> n_cats_or_dogs >> x;
  
  if (n_cats <= x && x <= n_cats + n_cats_or_dogs) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}