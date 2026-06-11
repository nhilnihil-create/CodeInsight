#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cin>>n;
    r=n%100;
    n=n/100;
    if(n>0 && r>0)
    {
        if(n>=1 && n<=12 && r>=1 && r<=12)cout<< "AMBIGUOUS";
        else if(n>12 && r>=1 && r<=12)cout<< "YYMM";
        else if(n>=1 && n<=12 && r>12)cout<< "MMYY";
        else cout<< "NA";
    }
    else if(n>=1 && n<=12 && r==0)cout<< "MMYY";
    else if(r>=1 && r<=12 && n==0)cout<< "YYMM";
    else cout<< "NA";

}

