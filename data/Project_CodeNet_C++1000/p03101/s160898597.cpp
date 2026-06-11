#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int main(void){
    int a,b;
    int h,w;
    int ans;
    cin>>a>>b>>h>>w;
    ans=a*b-h*b-(a-h)*w;
    cout<<ans<<endl;
}