#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int r,g,b,k,a,c,d;
    cin>>r>>g>>b>>k;
    if((r>g) && (r>b)){
       a= r*pow(2,k);
        cout<<g+b+a<<endl;
    }
    else if((g>r) && (g>b)){
        c=g*pow(2,k);
        cout<<r+b+c<<endl;
    }
    else {
        d=b*pow(2,k);
    cout<<r+g+d<<endl;
    }
    return 0;
}
