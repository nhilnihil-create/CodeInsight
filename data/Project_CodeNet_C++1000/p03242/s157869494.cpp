#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;

int main(){

    char n[3];


    for(int i = 0 ;i < 3; i++){
        cin >> n[i];
        if(n[i] == '9'){
            cout << '1';
        }
        else if(n[i] == '1'){
            cout << '9';
        }
        
    }

    cout << endl;

    
}