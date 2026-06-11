#include<bits/stdc++.h>
using namespace std;
int main(void){
    int flg[5];
    fill(flg, flg + 5, 0);
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        flg[a]++; flg[b]++;
    }
    int f = 1;
    for(int i = 1; i <= 4; i++)
        if(flg[i] < 1 || flg[i] > 2) f = 0;
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
} 