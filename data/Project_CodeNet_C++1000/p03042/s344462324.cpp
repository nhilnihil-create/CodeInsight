#include "bits/stdc++.h"
using namespace std;

int main(){
    int s;
    cin >> s;
    int left, right, okl = 0, okr = 0;
    left = s/100;
    right = s%100;
    if(left>0 && left < 13) okl = 1;
    if(right>0 && right < 13) okr = 1;
    if(okl){
        if(okr) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    } else {
        if(okr) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
    return 0;
}