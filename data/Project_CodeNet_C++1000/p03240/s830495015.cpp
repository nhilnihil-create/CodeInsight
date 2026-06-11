#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[101][3];
    for(int i=0;i!=n;i++)
    {
        cin>>num[i][0]>>num[i][1]>>num[i][2];
    }
    for(int i=0;i!=101;i++)
    {
        for(int j=0;j!=101;j++)
        {
            int first_non_zero_h=0;
            while(num[first_non_zero_h][2]==0)
            {
                first_non_zero_h++;
            }
            int h=abs(num[first_non_zero_h][0]-i)+abs(num[first_non_zero_h][1]-j)+num[first_non_zero_h][2];
            for(int k=0;k!=n;k++)
            {
                if(max(0,h-abs(num[k][0]-i)-abs(num[k][1]-j))!=num[k][2]) break;
                if(k==n-1)
                {
                    cout<<i<<' '<<j<<' '<<h;
                    return 0;
                }
            }
        }
    }
}
