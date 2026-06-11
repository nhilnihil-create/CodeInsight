#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    string S;
    cin >> S;

    if (S.size() != A+B+1) {
      cout << "No" << endl;
      return 0;
    }
  
    try {
        int num1 = stoi(S.substr(0, A));
        int num2 = stoi(S.substr(A+1, B));
    }
    catch (const invalid_argument& e) {
        cout << "No" << endl;
        return 0;
    }

    if (S[A]!='-') {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}