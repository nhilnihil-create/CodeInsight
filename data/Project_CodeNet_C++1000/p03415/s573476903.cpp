#include<bits/stdc++.h>
using namespace std;
int main()
{
    char arr[3][3];
    char result[3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>arr[i][j];
            if(i==j)
            {
                result[i]=arr[i][j];
            }

        }
    }
    for(int i=0; i<3; i++)
        cout<<result[i];
    return 0;
}
