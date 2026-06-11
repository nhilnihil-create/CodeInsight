#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    
    int bill = 700;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'o') bill += 100;
    }
    
    cout << bill << endl;
}

