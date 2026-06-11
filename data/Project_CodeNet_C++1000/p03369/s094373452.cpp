#include <iostream>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int topping = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'o') {
            topping++;
        }
    }
    cout << 700 + (100 * topping) << endl;
}