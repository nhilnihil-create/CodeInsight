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
    // + = 0 - = 1 とする
    int A,B,C,D,a,b,c,p,q;
    char aa,bb,cc;
    cin >> p;
    D = p % 10;
    p /= 10;
    C = p % 10;
    p /= 10;
    B = p % 10;
    p /= 10;
    A = p % 10;
    p /= 10;
    q = 0;
    for(a = 0;a < 2;a++){
        for(b = 0;b < 2;b++){
            for(c = 0;c < 2;c++){
                p = A;
                if(a == 0){
                    p += B;
                    aa = '+';
                }
                else{
                    p -= B;
                    aa = '-';
                }
                if (b == 0){
                    p += C;
                    bb = '+';
                }
                else{
                    p -= C;
                    bb = '-';
                }
                if (c == 0){
                    p += D;
                    cc = '+';
                }
                else{
                    p -= D;
                    cc = '-';
                }
                if(p == 7){
                    cout << A << aa << B << bb << C << cc << D << "=7" << endl;
                    q = 1;
                    break;
                }
            }
            if (q == 1){
                break;
            }
        }
        if (q == 1){
            break;
        }
    }
    
}