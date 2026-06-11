#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 5;
    int antenn[n];
    int k;
    bool flag = false;

    for(int i = 0; i<n; i++){
        cin>>antenn[i];
    }

    cin>>k;

    for(int i = 0; i<n-1; i++){
        for(int  j = 1; j<n-i; j++){
            if(abs(antenn[i]-antenn[j])>k){
                flag = true;
                break;    
            }
        }
    }

    if(flag){
        cout<<":(";
    }else{
         cout<<"Yay!";
    }
    
    return 0;
}