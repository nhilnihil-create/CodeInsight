#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

int high[1010];

void f(int n)
{
        if(n==1)
        {
                high[1]=1;
                return;
        }
        f(n-1);
        high[n]=high[n-1]+n;
}

main()
{
        f(1000);
        int l,r; cin>>l>>r;
        int d=r-l;
        cout<<high[d]-r<<endl;
}

