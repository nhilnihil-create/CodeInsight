#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    int n;
    cin>>n;
    bool ok=false;
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            int total= 4*i+7*j;
            if(total == n) ok=true;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}