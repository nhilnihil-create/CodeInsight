#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a, b, c;
    cin >> a >> b >> c ;
    //*/

    string str;
    int emp, a;
    
    cin >> emp >> a >> str;
    
    str.at(a - 1) = str.at(a - 1) -'A' +'a';
    
    cout << str << endl;

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a == b ){
        cout << a + b << endl;
    } else {
        cout << max(a, b) * 2 - 1 << endl;
    }
    //*/
    
    //cout << c / a * b << endl;

    return 0; 
}
