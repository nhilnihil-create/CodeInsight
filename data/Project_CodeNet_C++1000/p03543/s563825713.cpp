#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int a;
    cin >> a ;
    //*/
    
    //*
    vector<int> vec(4);
    //cin >> a.at(0) >> a.at(1) >> a.at(2) ;
    
    vec.at(0) = a / 1 % 10 ;
    vec.at(1) = a / 10 % 10 ;
    vec.at(2) = a / 100 % 10 ;
    vec.at(3) = a / 1000 % 10 ;
    
    //sort(vec.begin(), vec.end());
    //*/
    
    //*
    if( ( vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2) ) || ( vec.at(3) == vec.at(2) && vec.at(1) == vec.at(2) ) ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //*/
    
    //cout << b * 2 - a << endl;

    return 0; 
}
