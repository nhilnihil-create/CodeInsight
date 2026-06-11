#include <iostream>

using namespace std;

int main() {
    int D;
    cin >> D;
    
    string str="Christmas ";
    for(int i=0; i<25-D; i++) {
        str += "Eve ";
    }
    
    cout << str << endl;



    return 0;
    
}