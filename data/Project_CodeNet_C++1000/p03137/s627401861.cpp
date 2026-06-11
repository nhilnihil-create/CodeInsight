#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    int x[m];

    for(int i=0; i<m; i++){
        cin >> x[i];
    }

    int y[m-1];

    sort(x, x+m);

    for(int i=0; i<m-1; i++){
        y[i] = abs(x[i] - x[i+1]);
    }

    sort(y, y+m-1);
    

    int c = 0;

    for(int i=0; i<(m-n); i++){

        c+=y[i];
    }

    cout << c << endl;

}