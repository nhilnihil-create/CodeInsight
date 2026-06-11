#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    int s, cnt= 0, a;
    cin>>s;
    if(s == 1 || s == 2)
    {
        cout<<4<<endl;
        return 0;
    }
    else
    {
    while(s != 1)
    {
        if(s%2 == 0) s = s/2;
        else s = 3*s + 1;

        cnt++;
    }
    }
    cout<<cnt+2<<endl;
    return 0;

}

