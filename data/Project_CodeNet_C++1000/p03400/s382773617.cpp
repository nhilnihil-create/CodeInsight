#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,x;
    cin>>n>>d>>x;
    //cout<<n<<d<<x;
    int total=0;
    while(n--)
    {
        int a;
        cin>>a;
        int temp=1;
        for(int i=1;(i*a+1)<=d;i++)
        {
            temp++;
        }
        total+=temp;
    }
    cout<<total+x<<"\n";
}