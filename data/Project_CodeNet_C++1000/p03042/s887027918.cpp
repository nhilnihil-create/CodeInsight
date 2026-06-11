#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool yymm=false,mmyy=false;
    string s,fst="",lst="";
    cin>>s;
    for(int i=0; i<4; i++)
    {
        if(i<2)
            fst+=s[i];
        else
            lst+=s[i];
    }
    int f=stoi(fst);
    int l=stoi(lst);
    if(f>=0 && f<=99)
    {
        if(l>=1&& l<=12)
        {
            yymm=true;
        }
    }
    if(f>=1&& f<=12)
    {
        if(l>=0&&l<=99)
        {
            mmyy=true;
        }
    }
    if(yymm && mmyy)
        cout<<"AMBIGUOUS\n";
    else if( yymm ==true && mmyy== false)
    {
        cout<<"YYMM\n";
    }
    else if(yymm==false && mmyy==true)
    {
        cout<<"MMYY\n";
    }
    else
        cout<<"NA\n";
}
