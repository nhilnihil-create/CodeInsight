#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    string a;
    int ans = 0;
    cin >> a ;
    //*/

    if(a.at(0) == '+'){
        ans++;
    } else {
        ans--;
    }

    if(a.at(1) == '+'){
        ans++;
    } else {
        ans--;
    }

    if(a.at(2) == '+'){
        ans++;
    } else {
        ans--;
    }

    if(a.at(3) == '+'){
        ans++;
    } else {
        ans--;
    }

    /*
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    */
    
    /*
    if( a <= 8 && b <= 8 ){
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    */
    
    cout << ans << endl;

    return 0; 
}
