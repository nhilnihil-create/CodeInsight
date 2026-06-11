#include <iostream>
using namespace std;

int main() {
    int N, a;
    cin >> N >> a;

    //if (a <= 1000 && N <=10000 ) {

      if (a >=  N % 500) cout << "Yes" << endl;
      else cout << "No" << endl;

    //}

}