#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    //ｎこをｋ人にわける
    vector<int> pe(k);
    int flag = 0;
    while(true){
        for(int i=0; i<k; i++){
            pe.at(i) += 1;
            n--;
            if(n==0){
                flag = 1;
                break;
            }
        }

        if(flag == 1) break;
    }

    sort(pe.begin(), pe.end());

    cout << pe.at(k-1) - pe.at(0) << endl;
}