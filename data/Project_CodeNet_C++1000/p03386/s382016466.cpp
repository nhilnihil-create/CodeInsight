#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    

    for(int i=0; i<k; i++){
        if(a+i>=((double)a+b)/2){
            break;
        }
        cout<<a+i<<endl;
    }

    for(int i=k-1; i>=0; i--){
        if(b-i<((double)a+b)/2){
            continue;
        }
        /*if(b-i==last){
            continue;
        }*/
        cout<<b-i<<endl;
    }
}