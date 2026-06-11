#include <bits/stdc++.h>
using namespace std;

int main(){
    int Distance[5];
    for(int i=0;i<5;i++){
        cin >> Distance[i];
    }
    int K; cin >> K;
    bool flg;
    for(int i=1;i<5;i++){
        flg=true;
        for(int j=0;j<i;j++){
            if(Distance[i]-Distance[j]>K){
                flg=false;
                break;
            }
        }
    }
    if(flg==true){
        cout << "Yay!" << endl;
    }
    else{
        cout << ":(" << endl;
    }
}