#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
    string S;
    cin >> S;

    ll red = 0;
    ll blue = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == '0') {
            red += 1;
        } else {
            blue += 1;
        }
    }
    cout << min(red, blue) * 2 << endl;
}