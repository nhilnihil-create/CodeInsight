#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>

#define N_size 100000000000

using namespace std;

int main(){
    int A,B;
    cin >> A >> B;

    if((A % B) == 0 || (B % A) == 0)
        cout << A + B << endl;
    else
    {
        cout << B - A << endl;
    }
    
}
