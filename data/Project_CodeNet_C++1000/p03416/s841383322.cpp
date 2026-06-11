#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool palin_fun(ll a)
{
    ll arr[10],i=0;
    while(a>0)
    {
        arr[i]=a%10;
        a/=10;
        i++;
    }
    if(arr[0]==arr[4] && arr[1]==arr[3]) return 1;
    else return 0;
}


int main()
{
    ll a,b,cnt=0,i;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        if(palin_fun(i))
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
