#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main() {
    char c;
    for(int i=0;i<3;i++) {
        cin >>c;
        if(c=='1') cout << "9";
        else if(c=='9') cout << "1";
        else cout << c;
    }
    cout << endl;
}