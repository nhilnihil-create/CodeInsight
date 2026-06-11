#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int A,B,C;
    cin >> A >> B >> C;
    if((C>A&&C<B)||(C<A&&C>B)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}