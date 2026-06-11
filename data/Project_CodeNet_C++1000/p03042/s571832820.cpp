#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,d,x;
    cin>>s;
    d=s%100;

    s=s/100;
    s=s%100;
//cout<<d<<" "<<s;
    if((d<=12&&d!=0) && (s<=12 && s!=0))
        cout<<"AMBIGUOUS"<<endl;
    else if((d>12||d==0)&&(s>12 || s==0 ))
        cout<<"NA"<<endl;
    else if((d<=12&&d!=0))
        cout<<"YYMM"<<endl;
    else
         cout<<"MMYY"<<endl;




    }
