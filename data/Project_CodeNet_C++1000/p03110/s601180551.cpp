#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <iomanip>
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 0;
    double sum = 0;
    while (i < N) {
        double tmp1;
        string tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp2 == "JPY") sum += tmp1;
        else sum += tmp1 * 380000;
        i++;
    }
    cout << fixed << setprecision(6) << sum << endl;
}
