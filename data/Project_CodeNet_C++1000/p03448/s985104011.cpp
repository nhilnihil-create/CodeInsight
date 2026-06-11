#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int X;
    cin>>X;
    int keynum=X/50;
    int count=0;
    for (int p=0;p<=a;p++){
        for (int q=0; q<=b; q++){
            for(int r=0;r<=c; r++){
                int keynum1=keynum;
                keynum1-=10*p+2*q+r;
                if(keynum1==0) count++;
            }
        }
    }
    cout<<count<<endl;
}