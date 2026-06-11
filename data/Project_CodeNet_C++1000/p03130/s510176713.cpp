#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;
    int a[6];
    int c[4]={};

    for (int i = 0; i < 6; i++){
        cin >> a[i];
    }

    for(int i = 0; i < 6; i++){
        if(1==a[i]) c[0]++;
        else if(2==a[i]) c[1]++;
        else if(3==a[i]) c[2]++;
        else if(4==a[i]) c[3]++;
    }

    if(c[0]<3 && c[1]<3 && c[2]<3 && c[3]<3)cout << "YES" << endl;
    else cout << "NO" << endl;

}