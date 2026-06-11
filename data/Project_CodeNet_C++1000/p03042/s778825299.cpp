#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,l;
    cin>>n;
    f=n/100;
    l=n%100;
    if(f<=12&&l<=12&&f!=0&&l!=0)
        cout<<"AMBIGUOUS"<<endl;
    else if((f>12||f==0)&&l<=12&&l!=0)
        cout<<"YYMM"<<endl;
    else if((l>12||l==0)&&f<=12&&f!=0)
        cout<<"MMYY"<<endl;
    else
        cout<<"NA"<<endl;
}
