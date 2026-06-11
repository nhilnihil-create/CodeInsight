#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<int> num;
    vector<char> c(3);

    cin >> s;

    for(int i = 0; i < 4; i++){
        num.push_back(s[3 - i] - '0');
    }

    int ans = num.at(3);

    for(int bit = 0; bit < (1 << 3); bit++){
        for(int j = 0; j < 3; j++){
            if(bit & (1 << j)){
                ans = ans + num.at(j);
                c.at(j) = '+';
            }else{
                ans = ans - num.at(j);
                c.at(j) = '-';
            }
        }

        if(ans == 7){
            break;
        }

        ans = num.at(3);
    }

    cout << num.at(3) << c.at(2) << num.at(2) << c.at(1) << num.at(1) << c.at(0) << num.at(0) << "=7" << endl;
}