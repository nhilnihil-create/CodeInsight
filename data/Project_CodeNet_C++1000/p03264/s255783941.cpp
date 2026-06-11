#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int a;
    cin >> a ;
    //*/

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    */
    
    /*
    if( a % b == 0 ){
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    */
    
    cout << ( a / 2 ) * ( a / 2 + a % 2 ) << endl;

    return 0; 
}
