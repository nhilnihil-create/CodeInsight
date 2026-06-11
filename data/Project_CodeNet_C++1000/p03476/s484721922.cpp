#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,l,r,Q;
    vector<bool> issosu(100100,true),islike2017(100100,false);
    issosu[0] = false;
    issosu[1] = false;
    for(i = 2;i < 100099;i++){
        if(issosu[i]){
            if(issosu[(i + 1) / 2]){
                islike2017[i] = true;
            }
            for(j = i * 2;j < 100099;j += i){
                issosu[j] = false;
            }
        }
    }
    vector<int> ruisekiwa(100101,-1);
    for (i = 0; i < 100099; i++){
        if (islike2017[i]){
            ruisekiwa[i] = ruisekiwa[i - 1] + 1;
        }
        else{
            ruisekiwa[i] = ruisekiwa[i - 1];
        }
    }
    cin >> Q;
    for(i = 0;i < Q;i++){
        cin >> l >> r;
        cout << ruisekiwa[r] - ruisekiwa[l - 1] << endl;
    }
}