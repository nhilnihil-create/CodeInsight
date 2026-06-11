#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int tuikaryoukin = 0;

    for(int i=0; i<3; i++) {

        if(s.at(i) == 'o')
        tuikaryoukin++;

    }

    tuikaryoukin *= 100;

    cout << 700 + tuikaryoukin << endl;

}