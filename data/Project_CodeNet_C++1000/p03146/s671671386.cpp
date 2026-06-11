#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool chk=false;
    int A;
    cin >> A;
    vector<int> B(1000000);
    B.at(0)=A;
    int count=0;
    for(int i=1; i<10000001; i++)
    {
    if(A%2==0)
    {
        A=A/2;
        B.at(i)=A;
        count++;
    }
    else
    {
        A=3*A+1;
        B.at(i)=A;
        count++;
    }
    for(int j=0; j<i; ++j)
    {
        if(B.at(i)==B.at(j))
        {
            chk=true;
        }
    }
    if(chk)
    {
         break;
    }
    }
    cout << count+1 <<endl;
}