#include <iostream>
#include <string>
using namespace std;

int main (void){
    int n = 700;
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'o'){
            n += 100;
        }
    }
    cout << n << endl;
    return 0;
}
