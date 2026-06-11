#include<iostream>
using namespace std;
int main()
{
    int i,j;
    char str[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>str[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j)
            cout<<str[i][j];
        }
    }
    cout<<endl;
    return 0;
}
