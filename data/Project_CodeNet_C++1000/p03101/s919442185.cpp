//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long H,W,h,w,r,c;
    cin>>H>>W>>h>>w;
    r=abs(H-h);
    c=abs(W-w);
    cout<<r*c<<endl;

}


