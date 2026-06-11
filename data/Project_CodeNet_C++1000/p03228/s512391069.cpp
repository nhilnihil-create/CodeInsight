#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <sstream>
#include <numeric>
using namespace std;

int main(){
    int a,b,k ;
    cin >> a >> b >> k ;
    bool nowa = true ;
    for (size_t i = 0; i < k; i++)
    {
        if (nowa == 1)
        {
            b += a/2 ;
            a = a/2 ;
            nowa = 0 ;
        }else
        {
            a += b/2 ;
            b = b/2 ;
            nowa = 1 ;
        }
        
        
    }
    cout << a << " " << b << endl ;
}