#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, x, i, counter = 0;

    cin >> N >> x;
    //cout << N << " " << x << endl;

    for(i = N; i >= x; i--){
        //cout << i << endl;
        counter++;
    }

    cout << counter << endl;

    return 0;

}
