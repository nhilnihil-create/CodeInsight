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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    set<int>s;
    map<int,int>mp;
    while(n--)
    {
        int a;
        cin>>a;
        s.insert(a);
        mp[a]++;
    }
    vector<pair<int,int> >v;
    for(auto i:s)
    {
        v.push_back({mp[i],i});
    }
    int cnt=0;
    if(v.size()>k){
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-k;i++)
            cnt+=v[i].first;
    }
    cout<<cnt<<endl;
    return 0;
}
