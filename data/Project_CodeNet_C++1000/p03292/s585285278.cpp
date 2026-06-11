#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a;
    cin >> a ;
    */

    //*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a % 2 == 0 ){
        cout << a << endl;
    } else {
        cout << a * 2 << endl;
    }
    */
    
    cout << vec.at(2) - vec.at(0) << endl;

    return 0; 
}
