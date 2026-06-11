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
const int MAX = 1e9;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
vector<ll>v;
ll check(int n)
{
    map<int,int>mp;
    set<int>s;
    while(n)
    {
        s.insert(n%10);
        mp[n%10]++;
        n/=10;
    }
    if(mp[7] && mp[3] && mp[5] && s.size()==3)
        return 1;
    return 0;
}
void recur(ll n)
{
    if(n>MAX)
        return;
    if(check(n))
        v.push_back(n);
    recur(n*10+3);
    recur(n*10+5);
    recur(n*10+7);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    recur(0);
    sort(all(v));
    int cnt=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]<=n){
            cnt++;
        }
    }
    cout<<cnt<<endl;




    return 0;
}
