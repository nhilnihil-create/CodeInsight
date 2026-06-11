#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=100000;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for (int p=2; p*p<=n; p++)
        if (prime[p] == true)
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
    int c[100001];
    memset(c,0,sizeof(c));
    for(int i=3;i<=100000;i++)
        if(i%2==1 && prime[i] && prime[(i+1)/2])
            c[i]++;
    for(int i=3;i<=100000;i++)
        c[i]=c[i]+c[i-1];
 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[b]-c[a-1]<<endl;
    }
 
}