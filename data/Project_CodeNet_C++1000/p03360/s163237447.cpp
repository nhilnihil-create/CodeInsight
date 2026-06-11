#include <bits/stdc++.h>
using namespace std;

int main(){

    int array[3], k;
    cin >> array[0] >> array[1] >> array[2] >> k;
    sort(array, array+3);

    while(k--){
        array[2] *= 2;
    }
    cout << array[0] + array[1] + array[2] << endl;
    return 0;
}