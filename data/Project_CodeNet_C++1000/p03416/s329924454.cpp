#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    int count =0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(i%10==((i/10000)%10) && (i/10)%10==(i/1000)%10)
        {
            count++;
        }

    }
    cout<<count<<endl;





    return 0;
}
