#include<iostream>
using namespace std;
int main()
{
    int n,y;
    cin>>n>>y;
    for(int a=0;a<=n;a++)
    {
        for(int b=0;b<=n-a;b++)
        {
            int c=n-a-b;
            if(a*10000+b*5000+c*1000==y)
            {
                cout<<a<<" "<<b<<" "<<c<<" ";
                return 0;
            }
        }
    }
    cout<<"-1"<<" "<<"-1"<<" "<<"-1";
}
