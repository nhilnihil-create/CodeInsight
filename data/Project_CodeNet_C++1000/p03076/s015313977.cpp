#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare( int a , int b)
{
    return a% 10 < b%10;
}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    sort(a , a+5 , compare);
    int ans =0;
    bool found = false;
    for(int i=0;i<5;i++)
    {
        if( a[i] %10 != 0 && !found  )
        {
            ans += a[i];
            found = true;
        } else
        {
            int temp = a[i] %10;

            if(temp != 0)
            ans += a[i] + 10-temp ;
            else
                ans += a[i];
        }
    }
    cout<<ans;
}
