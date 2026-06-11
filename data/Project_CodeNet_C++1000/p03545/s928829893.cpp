#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int S;
    cin >> S;
    int A, B, C, D;
    A = S / 1000;
    B = (S - A*1000) / 100;
    C = (S - A*1000 - B*100) / 10;
    D = (S - A*1000 - B*100 - C*10);
    vector<string> vec(3);
    vector<int> N = {B, C, D};
    for(int i = 0; i < 8; i++){
        int num = A;
        for(int j = 0; j < 3; j++){
                if(((i >> j) & 1) == 1){
                vec.at(j) = "+";
                num += N.at(j);
            }else{
                vec.at(j) = "-";
                num -= N.at(j);
            }
        }
        if(num == 7){
            cout << A << vec.at(0) << B << vec.at(1) << C << vec.at(2) << D <<  "=7" << endl;
            return 0;
        }
    }
}