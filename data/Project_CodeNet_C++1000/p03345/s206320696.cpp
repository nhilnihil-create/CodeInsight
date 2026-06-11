#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    lli A, B, C, K;
    cin >> A >> B >> C >> K;
    lli tmpA, tmpB, tmpC;
    /*for (lli i = 0; i < K; i++)
    {
        tmpA = B + C;
        tmpB = C + A;
        tmpC = A + B;
        A = tmpA;
        B = tmpB;
        C = tmpC;
    }*/
    if (abs(A - B) > pow(10, 18))
    {
        cout << "Unfair" << endl;
    }
    else if(K%2==0)
    {
        cout << A-B << endl;
    }else if(K%2==1){
    	cout << B - A <<endl;
    }
    return 0;
}