#include <iostream>
using namespace std;

int main() {
    int cnt=0;
    char c;
    for (int i = 0; i < 4; ++i) {
        cin>>c;
        c == '+' ? (cnt++) : (cnt--);
    }
    cout << cnt <<endl;
}
