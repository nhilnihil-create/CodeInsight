#include<bits/stdc++.h>
using namespace std;
int T;
long long a,b;
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin>>a>>b;
        if (b<a)swap(b,a);
        long long l=sqrt(a*b-1);
        long long r=l;
        while (r&&r*(l+1)>=a*b)r--;
        bool sig1=0,sig2=0,sig3=0;
        if (l>=a)sig1=1;
        if (r>=b)sig2=1;
        if (l*r<a*b-1&&(l*(r+1)>=a*b||(l+1)*r>=a*b)&&l!=a)sig3=1;
        cout<<l+r-sig1-sig2-sig3<<endl;;
    }
    return 0;
}