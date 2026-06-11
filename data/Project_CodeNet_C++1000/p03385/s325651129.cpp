#include <iostream>
using namespace std;

int main() {
    char c,x=0;
    for (int i = 0; i < 3; ++i) {cin>>c;x^=c;}
    cout << (x == '`' ? "Yes" : "No") << endl;
}
