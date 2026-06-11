#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    vector<int> vc(4,0);
    int abcd;
    cin >> abcd;
    for(int i=0; i<4; i++){
        int keta = abcd%10;
        abcd /= 10;
        vc[3-i] = keta;
    }

    for(int bit=0; bit<(1<<3); bit++){
        vector<bool> plusminus(3, false);
        int tmp_num = vc[0];
        for(int i=0; i<3; i++){
            if(bit & 1<<i) plusminus[i] = true;
        }
        for(int i=0; i<3; i++){
            if(plusminus[i]) tmp_num += vc[i+1];
            else tmp_num -= vc[i+1];
        }
        if(tmp_num == 7){
           cout << vc[0];
           for(int i=0; i<3; i++){
               if(plusminus[i]) cout << '+';
               else cout << '-';
               cout << vc[i+1];
           }
           cout << '=' << 7 << endl;
           break;
        }
    }

    return 0;
}
