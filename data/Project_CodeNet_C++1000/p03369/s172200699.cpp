#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;

    int count;
    if(S[0] == 'o') count++;
    if(S[1] == 'o') count++;
    if(S[2] == 'o') count++;

    cout << 700 + count*100 << endl;
}