#include<bits/stdc++.h>
#define int long long
using namespace std;
 

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

int find(int x)
{
    int cnt=0;
    while (x)
    {
        cnt+=x%10;
        x/=10;
    }
    return cnt;       
}

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int k;
    cin>>k;
    
    vector<int>lol;
    int add=1;
    int z=1e16;
    for(int i=1;i<=z;i+=add)
    {
        long double x=i;
        long double y=find(i);
        long double xx=i+add;
        long double yy=find(i+add);
        x/=y;
        xx/=yy;
        if(x>xx)
        {
            i-=add;
            add*=10;
        }
        else
        {
            lol.push_back(i);
        }        
    }

    for(int i=0;i<k;i++)
        cout<<lol[i]<<'\n';
}
