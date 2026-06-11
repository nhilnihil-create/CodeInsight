#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int l[n];
    int N=1;
    for(int i=0;i<n;i++){
        cin>>l[i];
        N*=4;
    }
    int m=1000000000;
    for(int i=0;i<N;i++){
        int A=0,B=0,C=0;
        int cost=-30;
        int I=i;
        for(int j=0;j<n;j++){
            if(I%4)cost+=10;
            if(I%4==1)A+=l[j];
            if(I%4==2)B+=l[j];
            if(I%4==3)C+=l[j];
            I/=4;
        }
        if(A==0 || B==0 || C==0)continue;
        m=min(m,cost+abs(A-a)+abs(B-b)+abs(C-c));
    }
    cout<<m<<endl;
    return 0;
}