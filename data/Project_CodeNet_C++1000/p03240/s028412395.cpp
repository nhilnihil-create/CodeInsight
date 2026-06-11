#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    vector<int> h(N);
    int i = 0;
    int Max = 0;
    long min = 10e9;
    while(i < N){
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] < min) min = h[i];
        if (h[i] > Max) Max = h[i];
        i++;
    }
    i = 0;
    int j = 0; int k = 0;
    int flag = 0;
    while (i <= 100) {
        j = 0;
        while (j <= 100) {
            k = Max;
            while (Max <= k && k <= Max + 200) {
                int l = 0;
                int flag2 = 1;
                while (l < N) {
                    int value = 0;
                    value = max(k - abs(i - x[l]) - abs(j - y[l]),0);
                    if ( value != h[l]) {
                        flag2 = 0;
                        break;
                    } 
                    l++;
                }
                if (flag2) {
                    flag = 1;
                    break;
                }
                k++; 
            }
            if (flag) break;
            j++;
        }
        if (flag) break;
        i++;
    }
    cout << i << " " << j << " " << k << endl;
}
