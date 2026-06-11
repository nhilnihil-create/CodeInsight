#include<iostream>
using namespace std;
int main()
{
    int S;
    cin >> S;
    int Y = S/100;
    int M = S%100;
    if(((Y>=1)&&(Y<=12))&&((M>=1)&&(M<=12)))
    {
        cout<<"AMBIGUOUS";
    }
    else
    {
        if((Y>=1)&&(Y<=12))

        {
            cout<<"MMYY";
        }
        else if((M>=1)&&(M<=12))

        {
            cout<<"YYMM";
        }
        else
        {
            cout<<"NA";
        }
    }

}
