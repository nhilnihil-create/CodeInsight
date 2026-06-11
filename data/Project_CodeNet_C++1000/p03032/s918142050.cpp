/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
lli a[55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,k=0;lli res=0ll;
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<=min(n,k);++i)
        for(int j=0;(i+j)<=min(n,k);++j)
        {
            vector<lli> aux;
            lli temp=0ll;
            for(int l=0;l<i;++l)
            {
                aux.pb(a[l]);
                temp+=a[l];
            }
            for(int l=0;l<j;++l)
            {
                aux.pb(a[n-l-1]);
                temp+=a[n-l-1];
            }
            sort(aux.begin(),aux.end());
            for(int l=0;l<min(k-i-j,(int)aux.size());++l)
                if(aux[l]<0)
                    temp-=aux[l];
            res=max(res,temp);
        }
    cout<<res<<endl;
}