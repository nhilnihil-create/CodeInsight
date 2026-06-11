#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    int n;

    cin >> n;

    double x[n];
    string u[n];

    for(int i=0; i<n; i++){
        cin >> x[i] >> u[i];
    }

    double rb = 0;
    int jpy = 0;

    for(int i=0; i<n; i++){
        if(u[i] == "JPY"){
            jpy += x[i];
        } else {
            rb += x[i];
        }
    }

    double s = jpy + (rb*380000.0);

    cout << s << endl;

}