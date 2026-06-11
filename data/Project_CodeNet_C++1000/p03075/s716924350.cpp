#include<bits/stdc++.h>
using namespace std;
int main(){
    int adad[5],k,eror=0;
    for(int i=0;i<5;i++){
        cin>>adad[i];
    }
    cin>>k;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(adad[j]-adad[i]>k){
                eror=1;
                break;
            }
        }
        if(eror==1){
            break;
        }
    }
    if(eror==1){
        cout<<":(";
    }
    else{
        cout<<"Yay!";
    }
}
