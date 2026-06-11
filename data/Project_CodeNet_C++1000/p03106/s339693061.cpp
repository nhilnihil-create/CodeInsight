#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm> 
using namespace std;
int main(void){
    int a,b,k; cin >> a >> b >> k;
    int i = 1;
    vector<int> num;
    while (i <= 100) {
        if (a % i == 0 && b % i == 0) num.push_back(i);
        i++;
    }
    sort(num.begin(), num.end(), greater<int>());
    cout << num[k-1] << endl;
}
