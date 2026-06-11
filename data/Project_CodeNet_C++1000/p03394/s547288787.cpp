#include<bits/stdc++.h>
using namespace std;
int n,t[9];

int main(){
    cin >> n;
    if(n==3)printf("2 5 63");
    else
    {
        if(n&1)
            t[0]=6,t[1]=2,t[2]=10,t[3]=3,t[4]=9,t[5]=4,t[6]=8,t[7]=12;
        else
            t[0]=2,t[1]=10,t[2]=3,t[3]=9,t[4]=4,t[5]=8,t[6]=6,t[7]=12;
        for(int i=0; i<min(n,8); i++) cout << t[i] << ' ';
        for(int i=8; i<n; i++){
          t[i%8]=t[i%8]+12;
          cout << t[i%8] << ' ';
        }
    }
    return 0;
}
