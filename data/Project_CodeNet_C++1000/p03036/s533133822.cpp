#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,d,x2000;
    cin>>r>>d>>x2000;
    int i;
    for(i=0;i<10;i++){
        cout<<r*x2000-d<<endl;
        x2000=r*x2000-d;
    }
}