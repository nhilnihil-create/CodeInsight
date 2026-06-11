#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n ;
    cin >> n;
    string x[n];
    
    double u[n];

    double bit = 380000.0;

    double all = 0;

    for(int i = 0; i < n; i++){
        cin >> u[i];
        cin >> x[i];
        if(x[i] == "JPY"){
            all += u[i];
        }else{
            all += u[i] * bit;
        }

    }

    cout << all << endl;
}