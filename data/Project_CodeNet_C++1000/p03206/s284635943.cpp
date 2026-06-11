#include <iostream>
using namespace std;
int main() {
    int D; cin >> D;
    string S = "Christmas";
    for (int i = 0; i < 25 - D; i++) S += " Eve";
    cout << S << endl;
}