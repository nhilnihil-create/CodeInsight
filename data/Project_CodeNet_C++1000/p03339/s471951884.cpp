#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    char a[n + 1];
    a[0] = ' ';
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> w(n + 2, 0);
    vector<int> e(n + 2, 0);

    for(int i = 0; i <= n; i++){
        if(a[i] == 'W'){
            w[i + 1] = w[i] + 1;
            e[i + 1] = e[i];

        }
        else if(a[i] == 'E') {
            e[i + 1] = e[i] + 1;
            w[i + 1] = w[i];
        }
    }

    
    int minv = 10000000;
    for(int k = 1; k <= n; k++){
        minv = min(minv, w[k] + e[n + 1] - e[k + 1]);
    }

    printf("%d\n", minv);

    return 0;

}