#include <bits/stdc++.h>
using namespace std;
int main(void){
    int H,W,h,w;
    cin>>H>>W>>h>>w;
    int sum=H*W;
    sum-=h*W;
    sum-=w*H;
    sum+=h*w;
    cout<<sum<<endl;
}