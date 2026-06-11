#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int ans=0;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                int sum=i*500+j*100+50*k;
                if(sum==x) ans++;
            }
        }
    }
    cout<<ans<<endl;
    
}