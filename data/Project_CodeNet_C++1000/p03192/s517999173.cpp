#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>

#define div1 1000000007

using namespace std;

int main(void)
{
    string N;
    int i, ans=0;

    cin >> N;

    for(i=0; i<=3; i++){
        if(N[i] == '2'){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}