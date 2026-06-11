#include <bits/stdc++.h>
using namespace std;

int main(){
    int antena[5];
    int k;
    for(int i=0;i<5;i++){
        cin >> antena[i];
    }
    cin >> k;
    
    bool f = false;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(antena[j]-antena[i] > k){
                f = true;
            }
        }
    }
    if(f){
        cout << ":(";
    }else{
        cout << "Yay!";
    }
    return 0;
}