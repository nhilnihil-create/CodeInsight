#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <regex>

using namespace std;
int main(void){
    string S; int K;
    cin >> S >> K;
    smatch match;
    string sub = S.substr(0,K);
    if (regex_search(sub, match, regex("[2-9]"))) {
        cout << match.str() << endl;
    } else {
        cout << 1 << endl;
    }
}
