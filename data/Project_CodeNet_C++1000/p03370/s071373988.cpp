#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int sum=0;
    cin>>a>>b;
    int c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
        sum=sum+c[i];
    }
    int min = c[0];
    for(int j=1;j<a;j++){
        if(min>c[j]){
            min=c[j];
        }
    }
    if(sum>=b){
        cout<<a<<endl;
    }
    else{
        int d=b-sum;
        int e=d/min;
        cout<<e+a<<endl;
    }
    return 0;
}
