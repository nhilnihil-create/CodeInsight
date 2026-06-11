#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    string a;
    int cnt = 0;
    //int a, b, c;
    cin >> a ;
    //*/
    
    if(a.at(0)== 'o'){
        cnt++;
    }
    
    if(a.at(1)== 'o'){
        cnt++;
    }
    
    if(a.at(2)== 'o'){
        cnt++;
    }
    
    /*
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    */
    
    /*
    if(b >= c - a && c - a >= 0 ){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    */
    
    cout << 700 + 100 * cnt << endl;

    return 0; 
}
