// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;

//int n, m, x;
//
//vector<int> c(12,0);
//vector<vector<int>> A(12, vector<int>(12, 0));



int main()
{
    int n, k,tmp;
    int min= 2147483647;
    cin >> n >> k;

    vector<double> H(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    sort(H.begin(), H.end());

    for (int i = 0; i < n-k+1; i++) {
        tmp = H[i + k - 1] - H[i];
        if (tmp < min) {
            min = tmp;
        }
    }
    

    printf("%d", min);


    return 0;

}