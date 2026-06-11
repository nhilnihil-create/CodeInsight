#include <bits/stdc++.h>
#define rep(i,N) for (int i=0;i<N;i++)
using namespace std;

int main(void){
    //input
    int a,b,c,dis;
    cin >>a>>b>>c>>dis;
     
    //communicate a and c
    if (abs(a-c)<=dis){
        cout<<"Yes"<<endl;
    }
    else if (abs(a-b)<=dis && abs(b-c)<=dis){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}