#include <iostream>
using namespace std;
 
int main() {
    int y=700;
    string S;
    
    cin >> S;
    
    if(S[0]=='o') y += 100;
    if(S[1]=='o') y += 100;
    if(S[2]=='o') y += 100;
    
    cout << y << endl;
    return 0;
}