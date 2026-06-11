#include <iostream>
using namespace std;
int main(void){
    char s;
    cin >> s;
    if(s=='T') cout << "A";
    if(s=='A') cout << 'T';
    if(s=='C') cout << 'G';
    if(s=='G') cout << 'C';
}