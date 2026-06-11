///I am Groot |*|
///19.09.2020>>08.55 PM
#include <iostream>
using namespace std;
int huhaha(int n)
{
    int rev=0;
    for(int i=n; i>0; i/=10)
    {
        rev=rev*10+i%10;
    }
    return rev;
}
int main()
{
    int x,y,cnt=0;
    cin>>x>>y;
    for(int i=x; i<=y; i++)
    {
        if(i==huhaha(i))
        {
            //cout<<x<<" ";
            cnt++;
        }
    }
    cout<<cnt;
}
