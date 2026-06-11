#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;

int main(){
    int x,y,n,m;

    cin >> n >> m >> x >> y;

    int xx[n];
    int yy[m];

    for(int i=0; i<n; i++){
        cin >> xx[i];
    }
    for(int i=0; i<m; i++){
        cin >> yy[i];
    }

    int xflag=0;
    int yflag=0;
    int z = 200;

    for(int i=x+1; i<=y; i++){
        for(int j=0; j<n; j++){
            if(xx[j] >= i){
                xflag=1;
            }
        }
        for(int j=0; j<m; j++){
            if(yy[j] < i){
                xflag=1;
            }
        }
        if(xflag==0 && yflag==0){
            z = i;
        }
        xflag = 0;
        yflag = 0;
        

    }

    if(z != 200){
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
}