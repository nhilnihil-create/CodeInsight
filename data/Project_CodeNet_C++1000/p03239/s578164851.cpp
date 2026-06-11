#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n , _t;
    cin >> n;
    cin >> _t;
    int c[n];
    int t[n];

    for(int i = 0; i <n; i++){
        cin >> c[i];
        cin >> t[i];
    }

    int min = 1001;

    for(int i = 0; i < n; i++){
        if(_t >= t[i] && c[i] < min){
            min = c[i];
        }
    }

    if(min == 1001){
        cout << "TLE" << endl;
    }else{
        cout << min << endl;
    }

}