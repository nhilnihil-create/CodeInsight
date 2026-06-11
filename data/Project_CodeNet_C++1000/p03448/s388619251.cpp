#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
using namespace std;

const double PI=acos(-1);

int main(){
    int a, b, c, x, cnt = 0;
    cin >> a >> b >> c >> x;
    for(int aa = 0; aa <= a; aa++){
        for(int bb = 0; bb <= b; bb++){
            for(int cc = 0; cc <= c; cc++){
                if((aa*500 + bb*100 + cc*50) == x){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}