#include<iostream>
using namespace std;
int main()
{
    int S;
    cin>>S;
    int A=S/100;
    int B=S%100;
    if(((A>=1)&&(A<=12))&&((B>=1)&&(B<=12)))
    {
        cout<<"AMBIGUOUS"<<endl;
    }
    else
    {
        if((A>=1)&&(A<=12))

        {
            cout<<"MMYY"<<endl;
        }
        else if((B>=1)&&(B<=12))

        {
            cout<<"YYMM"<<endl;
        }
        else
        {
            cout<<"NA"<<endl;
        }
    }
    return 0;
}
