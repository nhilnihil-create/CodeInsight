#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
int main(){
    long int N,p,i,j,a;
    cin >> N;
    a = 0;
    long int A[2][N];
    for(i = 0;i < 2;i++){
        for(j = 0;j < N;j++){
            cin >> p;
            A[i][j] = p;
        }
    }
    for(i = 0;i < N;i++){
        p = 0;
        for(j = 0;j <= i;j++){
            p += A[0][j];
        }
        for (j = i; j < N; j++)
        {
            p += A[1][j];
        }
        if(a < p){
            a = p;
        }
    }
    cout << a << endl;
}