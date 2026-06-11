#include <iostream>

using namespace std;

int main()
{
    int A,B,conf,max;
    ios::sync_with_stdio(false);
    cin >> A >> B;
    if(A >= B)
    {
        max = A;
    }
    else
    {
        max = B;
    }
    
    for (int i = 1 ; i<max+1 ; i++)
    {
        if((A*B*i)%2 == 0)
        {
            conf = 0;
        }
        else
        {
            cout << "Yes" << endl;
            conf = 1;
            break;
        }
        
    }
    if(conf == 0)
    {
        cout << "No" << endl;
    }
    return 0;
}