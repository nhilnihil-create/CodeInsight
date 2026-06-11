#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    int n,m,x,y; cin >> n >> m >> x >> y;
    vector<int> X(n);
    vector<int> Y(m);
    int z = -99;
    string answer = "War";
    int i = 0;
    while (i < n) {
        cin >> X[i];
        i++;
    }
    i = 0;
    while (i < m) {
        cin >> Y[i];
        i++;
    }
    while (z < 101) {
        if (x >= z || z > y) {
            z++;
            continue;
        }

        int flag = 1;
        i = 0;
        while (i < n) {
            if(X[i] >= z) {
                flag = 0;
                break;
            }
            i++;
        }
        i = 0;
        while (i < m) {
            if(Y[i] < z) {
                flag = 0;
                break;
            }
            i++;
        }
        if (flag) answer = "No War";
        z++;
    }
    cout << answer << endl;
}