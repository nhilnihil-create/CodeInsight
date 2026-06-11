#include <iostream>
using namespace std;

int main(){
    string s; cin >> s;

    int a0=0, a1=0;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') {
            a0++;
        } else {
            a1++;
        }
    }

    cout << min(a0, a1) * 2 << endl;

    return 0;
}