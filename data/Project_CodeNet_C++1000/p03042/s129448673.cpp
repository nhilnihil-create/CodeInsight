#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    int Q,R,N;
    cin>>S;
    N=stoi(S);
 if (S.length()==4){
     Q=N/100;
     R=N%100;
    if((Q>12||Q==0)&&R>0&&R<=12){
        cout<<"YYMM";
    }
    else if((R>12||R==0)&&Q>0&&Q<=12){
        cout<<"MMYY";
    }
    
    else if(R>=1&&R<=12&&Q>=1&&Q<=12){
        cout<<"AMBIGUOUS";
    }
    else{
        cout<<"NA";
    }
 }
    return 0;
}