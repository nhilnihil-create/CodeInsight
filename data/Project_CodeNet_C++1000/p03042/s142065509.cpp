#include<iostream>
#include <stdio.h>
#include<string>
#include<vector>
using namespace std;
 
int main(){
    int S;
    cin >> S;

    int front = S / 100;
    int end = S % 100;
    
    if(front >= 1 && front <= 12){
        if(end >= 1 && end <= 12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else{
        if(end >= 1 && end <= 12) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
}