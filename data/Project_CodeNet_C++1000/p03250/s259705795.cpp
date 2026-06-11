#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> numList(3);
    int i = 0;
    while (i < 3) {
        cin >> numList[i];
        i++;
    }
    sort(numList.begin(), numList.end(), greater<int>());
    int answer = numList[0] * 10 + numList[1] + numList[2];
    cout << answer << endl;
}