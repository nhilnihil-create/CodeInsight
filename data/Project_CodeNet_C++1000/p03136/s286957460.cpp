#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    int max = 0;
    int sum = 0;
    int i = 0;
    while (i < N) {
        int tmp;
        cin >> tmp;
        if (tmp > max) max = tmp;
        sum += tmp;
        i++;
    }
    max < sum - max ? cout << "Yes" << endl : cout << "No" << endl;
}