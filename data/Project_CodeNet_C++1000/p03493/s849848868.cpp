#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int a, cnt = 0;
    cin >> a ;
    //*/
    
    if(a % 10 == 1){
        cnt++;
    }
    a /= 10;
    
    if(a % 10 == 1){
        cnt++;
    }
    a /= 10;
    
    if(a % 10 == 1){
        cnt++;
    }
    a /= 10;
    
    /*
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    */
    
    /*
    if( ( vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2) ) || ( vec.at(3) == vec.at(2) && vec.at(1) == vec.at(2) ) ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    */
    
    cout << cnt << endl;

    return 0; 
}
