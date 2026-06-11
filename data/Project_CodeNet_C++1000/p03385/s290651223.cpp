#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int c=0;
    char a[3],abc[3]={'a','b','c'};
    cin>>a;
    for(int i=0;i<=2;i++)
    {
        if (a[0]==abc[i])
        {
            c++;
            continue;
        }
        else if (a[1]==abc[i])
        {
            c++;
            continue;
        }
        else if (a[2]==abc[i])
        {
            c++;
            continue;
        }
    }
        if (c!=3) cout << "No";
        if (c==3) cout << "Yes";
}
