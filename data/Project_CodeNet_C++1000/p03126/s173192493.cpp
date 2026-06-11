#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int n,m;

    cin >> n >> m;

    int k[n];

    int a[m];

    int r[m];

    for(int i=0; i<m; i++){
        r[i] = 0;
    }

    for(int i=0; i<n; i++){
        cin >> k[i];
        for(int j=0; j<k[i]; j++){
            cin >> a[j];
            //cout << a[j];
        }
        for(int j=0; j<k[i]; j++){
            r[a[j]-1]++;
        }
       // for(int i=0;i<m;i++){
            //cout << r[i];
       // }

    }

    int c=0;

    for(int i=0; i<m; i++){
        if(r[i] == n){
            c++;
        }
    }

    cout << c << endl;


}