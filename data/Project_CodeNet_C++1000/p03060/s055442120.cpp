#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    vector<int> v(N);
    int i = 0;
    int sum = 0;
    while (i < N) {
        cin >> v[i];
        i++;
    }
    i = 0;
    while (i < N) {
        int tmp;
        cin >> tmp;
        if (v[i] - tmp > 0) sum = sum + v[i] - tmp;
        i++;
    }
    cout << sum << endl;
}