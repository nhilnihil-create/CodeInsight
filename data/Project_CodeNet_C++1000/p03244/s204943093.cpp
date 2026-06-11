#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX],n;
int op1()
{
    int ans=0;
    int cnt=0,x=0,y=0;
    map<int,int>mp;
    set<int>s;
    vector<pair<int,int> >v;
    for(int i=0; i<n; i+=2)
    {
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    for(auto it:s)
        v.push_back({mp[it],it});
    sort(all(v));
    reverse(all(v));
    int X;
    ans=(n/2)-v[0].first;
    X=v[0].second;
    v.clear();
    s.clear();
    mp.clear();
    for(int i=1; i<n; i+=2)
    {
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    for(auto it:s)
        v.push_back({mp[it],it});
    sort(all(v));
    reverse(all(v));
    if(v[0].second==X)
    {
        if(v.size()==1)
            ans+=n/2;
        else
            ans+=(n/2)-v[1].first;
    }
    else
    {
        ans+=(n/2)-v[0].first;
    }
    return ans;
}
int op2()
{
    int ans=0;
    int cnt=0,x=0,y=0;
    map<int,int>mp;
    set<int>s;
    vector<pair<int,int> >v;
    for(int i=1; i<n; i+=2)
    {
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    for(auto it:s)
        v.push_back({mp[it],it});
    sort(all(v));
    reverse(all(v));
    int X;
    ans=(n/2)-v[0].first;
    X=v[0].second;
    v.clear();
    s.clear();
    mp.clear();
    for(int i=0; i<n; i+=2)
    {
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    for(auto it:s)
        v.push_back({mp[it],it});
    sort(all(v));
    reverse(all(v));
    if(v[0].second==X)
    {
        if(v.size()==1)
            ans+=n/2;
        else
            ans+=(n/2)-v[1].first;
    }
    else
    {
        ans+=(n/2)-v[0].first;
    }
    return ans;

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<min(op1(),op2())<<endl;

    return 0;
}
