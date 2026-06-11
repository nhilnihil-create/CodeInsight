#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,p,h[1000010],m=1,max=0;
    int n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            for(j=1;j<=i;j++)
            {
                if(i%j==0)
                {
                    c++;
                }
            }
            if(c==8)
            {
                max++;
            }
            c=0;
        }
    }
    cout << max << endl;
    
    return 0;

}
