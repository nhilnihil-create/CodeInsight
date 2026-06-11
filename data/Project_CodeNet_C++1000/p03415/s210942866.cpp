#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string S[3];
    for(int i=0; i<3; i++) cin >> S[i];
    for(int i=0; i<3; i++) cout << S[i][i]; cout << endl;
    return 0;    
}