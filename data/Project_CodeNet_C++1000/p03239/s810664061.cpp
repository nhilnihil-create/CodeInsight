#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    
    int n,T;
    cin >> n >> T;

    int c[n];
    int t[n];
    int r[n];

    for(int i=0; i<n; i++){
        cin >> c[i] >> t[i];
        if(t[i] <= T){
            r[i] = c[i];
        } else {
            r[i] = 1001;
        }
    }

    int min = 1001;

    for(int i=0; i<n; i++){
        if(min > r[i]){
            min = r[i];
        }
    }

    if(min != 1001){
        cout << min << endl;
    } else {
        cout << "TLE" << endl;
    }
    

   

}