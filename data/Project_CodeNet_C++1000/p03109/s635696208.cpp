#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <sstream> 

using namespace std;

int main(){
    string s ;
    cin >> s;
    replace(s.begin(), s.end(), '/', ' ');
    istringstream iss(s);

    string a[3];
    iss >> a[0] >> a[1] >> a[2];
    int num[3];
    int i = 0;
    for(i = 0; i < 3; i++){
        num[i] = stoi(a[i]);
        if(num[i] >  2019 && i == 0){
            cout << "TBD" << endl;
            i = 9;
        }else if(num[i] > 4 && i == 1){
            cout << "TBD" << endl;
            i = 9;
        }
    }

    if(i != 10){
        cout << "Heisei" << endl;
    }
}