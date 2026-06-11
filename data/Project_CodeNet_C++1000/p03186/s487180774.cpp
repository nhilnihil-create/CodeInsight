#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

main()
{
        int a,b,c; cin>>a>>b>>c;
        int cnt=0;
        bool poison=false;
        while(true)
        {
                if(!poison && c>0)
                {
                        c--;
                        cnt++;
                        poison=true;
                }else if(b>0)
                {
                        b--;
                        cnt++;
                        poison=false;
                }else if(a>0)
                {
                        a--;
                        poison=false;
                }

                if(c+b==0)break;
                if(poison && a+b==0)break;
        }

        cout<<cnt<<endl;
}
