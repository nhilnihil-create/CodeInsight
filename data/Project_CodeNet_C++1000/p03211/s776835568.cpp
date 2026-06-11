#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    char s[11];
    cin>>s;
    int len = strlen(s);
    double k;
    int num,diff=0,d=0;
    for(int i = 0; i<=len-3; i++){
        //num = 0,diff = 0;
        //k = 2;
        /*for(int j = i,k=2; j<(j+3),k>=0; j++,k--){
                double p = pow(10,k);
                num+=( (s[j]-48) * p);
                //k--;
        }*/
        //cout<<num<<endl;
        num = ((s[i]-48)*100)+((s[i+1]-48)*10)+((s[i+2]-48)*1);
        //cout<<num<<endl;
        diff = abs(num-753);
        if(i==0)d = diff;
        else d=min(d,diff);
    }
    cout<<d<<endl;
    return 0;
}
