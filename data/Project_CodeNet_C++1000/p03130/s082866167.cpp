#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c1=0,c2=0,c3=0,c4=0;
    for(int i=0;i<3;i++){
        cin >> a >> b;
        if(a==1)c1++;
        if(a==2)c2++;
        if(a==3)c3++;
        if(a==4)c4++;
        if(b==1)c1++;
        if(b==2)c2++;
        if(b==3)c3++;
        if(b==4)c4++;
    }
    if(c1==1&&c2==2&&c3==2&&c4==1)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}