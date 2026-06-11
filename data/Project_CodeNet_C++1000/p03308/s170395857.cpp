
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 0;
    int max = 0;
    int min = 1 + pow(10, 9);
    vector<int> a(N);
    while(a.size() > i){
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        } 
        if (a[i] < min) {
            min = a[i];
        }
        i++;
    }
    cout << max - min << endl;
}