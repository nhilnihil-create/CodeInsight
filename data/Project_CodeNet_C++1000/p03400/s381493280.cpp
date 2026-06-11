#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int n, d, x;
    cin >> n >> d >> x;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int choco = 0;
    for (int i=0; i<n; i++) {
        int tmp = 1;
        while (true) {
            if (tmp > d) break;
            choco++;
            tmp += a[i];
        }
    }
    cout << choco+x << '\n';
   return 0;
}