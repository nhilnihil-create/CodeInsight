#include <iostream>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int counter = 0;
    if(S[0] == 'o')  counter++;
    if(S[1] == 'o') counter++;
    if(S[2] == 'o') counter++;
    cout << 700 + (100 * counter) << endl;
    return 0;
}