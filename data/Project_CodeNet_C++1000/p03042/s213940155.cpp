#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    string s; cin >> s;

    int XX = atoi(s.c_str());

    int a = XX/100, b = XX%100;

    if(a==0 && b==0){
        cout << "NA" << endl;
    } else if(1<=a && a<=12){
        if(1<=b && b<=12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    } else {
        if(1<=b && b<=12) cout << "YYMM" << endl;
        else cout << "NA" << endl; 
    }
    
    return 0;
}