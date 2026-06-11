#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,tmp=0,i=0;
    cin >> n;
    bool ok=false;
    while(true){
        tmp=i*4;
        while(true){
            if(tmp==n)ok=true;
            tmp+=7;
            if(tmp>100)break;
        if(ok)break;
        }
        i++;
        if(i==26)break;
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}