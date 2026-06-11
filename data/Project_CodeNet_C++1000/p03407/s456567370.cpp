#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const int MOD = 1000000007;
const int INF = INT_MAX;



int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a+b < c){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }



    return 0;
}




//              g++ -std=c++1z  ]