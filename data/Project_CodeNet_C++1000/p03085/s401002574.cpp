#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a, b , c, d;
    cin >> a >> b >> c >> d ;
    //*/

    char a;
    cin >> a;
    if(a == 'A'){
        a = 'T';
    } else if (a == 'T'){
        a = 'A';
    } else if (a == 'C'){
        a = 'G';
    } else if (a == 'G'){
        a = 'C';
    }

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( b / a < c ){
        cout << b / a << endl;
    } else {
        cout << c << endl;
    }
    //*/
    
    cout << a << endl;

    return 0; 
}
