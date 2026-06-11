#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    int s;

    cin >> s;

    int x,y;

    x = (s - s%100)/100;
    y = s%100;

    int YYMM = 0;
    int MMYY = 0;

    if(x >= 0 && y <=12 && y >= 1){
        YYMM++;
    }
    if(y >= 0 && x <=12 && x >= 1){
        MMYY++;
    }

    if(YYMM == 1 && MMYY == 1){
        cout << "AMBIGUOUS" << endl;
    } else if(YYMM == 0 && MMYY == 1){
        cout << "MMYY" << endl;
    } else if(YYMM == 1 && MMYY == 0){
        cout << "YYMM" << endl;
    } else {
        cout << "NA"<< endl;
    }

}