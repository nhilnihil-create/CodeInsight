#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    string a;
    cin >> a ;
    //*/
    
    if(a.at(0) == '1'){
        a.at(0) = '9';
    } else {
        a.at(0) = '1';
    }

    if(a.at(1) == '1'){
        a.at(1) = '9';
    } else {
        a.at(1) = '1';
    }

    if(a.at(2) == '1'){
        a.at(2) = '9';
    } else {
        a.at(2) = '1';
    }

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a * b % 2 == 0 ){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    //*/
    
    cout << a << endl;

    return 0; 
}
