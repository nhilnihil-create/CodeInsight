#include <bits/stdc++.h>

using namespace std;

int main(){

    int n[3], k, i, j, l = 0, m = 2, temp, maxim;

    cin >> n[0] >> n[1] >> n[2] >> k;

    int sum[k*3];

    for(i = 0; i < k; i++){
        for(j = 0; j < 3; j++){
            temp = n[j];
            n[j] *= m;
            sum[l] = n[0] + n[1] + n[2];
            l++;
            n[j] = temp;
        }
        m *= 2;
    }

    maxim = sum[0];

    for(i = 0; i < l; i++){
        if(maxim < sum[i]){
            maxim = sum[i];
        }
    }

    cout << maxim << endl;

    return 0;
}



