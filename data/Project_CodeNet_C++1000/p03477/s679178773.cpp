#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int l=a+b;
    int r=c+d;
    if(l==r)
        cout<<"Balanced"<<endl;
    else if(l>r)
        cout<<"Left\n";
    else if(l<r)
        cout<<"Right\n";
}
