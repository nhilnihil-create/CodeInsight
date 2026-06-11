#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int s = 0;
    int s2 = 0;
    int a;
    cin >> a;

    s = a / 100;
    s2 = a % 100;

    if(s <= 12 && s >= 1){
        if(s2 <= 12 && s2 >= 1){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "MMYY" << endl;
        }
    }else{
        if(s2 <= 12 && s2 >= 1){
            cout << "YYMM" << endl;
        }else{
            cout << "NA" << endl;
        }
    }

}