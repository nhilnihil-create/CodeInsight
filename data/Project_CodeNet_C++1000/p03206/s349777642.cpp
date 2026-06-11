#include <iostream>
using namespace std;
int main() {
    int d;
    cin >> d;
    string s = "Christmas";
    for (int i=0; i+d<25; i++) {
        s += " Eve";
    }
    cout << s << endl;
}