#include <iostream>
using namespace std;
 
int main() {
    int y=700;
    string S;
    
    cin >> S;
    
    if(S[3] != '8') S[3]='8';
    
    cout << S << endl;
    
    return 0;
}