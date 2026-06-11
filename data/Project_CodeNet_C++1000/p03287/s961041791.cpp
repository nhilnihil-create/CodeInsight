#include <bits/stdc++.h>
#define ll long long
#define inf 100000000000000000
#define mod 1000000007
#define endl '\n'
#define omarshagar                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
bool check(int mn,int mx,bool arr[])
{
    for(int i=mn;i<=mx;i++)
    {
        if(arr[i]==0)return 0;
    }
    return 1;
}
int main() {
    omarshagar
   ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]%=m;
       // cout<<arr[i]<<" sss"<<endl;
    }
    ll sum[n];
    ll ss=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        sum[i]=(arr[i]+ss)%m;
        ss=sum[i];
        ss%=m;
       // cout<<"vv "<<ss<<endl;
        if(sum[i]==0){res++;/*cout<<i<<endl;*/};
    }

    sort(sum,sum+n);


    for(int i=0;i<n;)
    {
        ll tmp=sum[i];
        ll cnt=0;
        for(int ii=i;ii<n;ii++)
        {
            if(sum[ii]!=tmp)break;
            cnt++;
        }
        i+=cnt;
          //  cout<<cnt<<endl;
        if(cnt>1)
        {
            res+=(cnt*(cnt-1))/2.0;
        }
    }
    cout<<res<<endl;
    return 0;
}
/*
 1
 4
1000
0010
0100
0001


 */
