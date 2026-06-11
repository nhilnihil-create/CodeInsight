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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,cnt=0;
    map<int,int>mp;
    set<int>s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        s.insert(a);
        mp[a]++;
    }
    for(auto i:s){
        int cur=mp[i];
        if(mp[i]==i)
            continue;
        else if(mp[i]<i)
            cnt+=mp[i];
        else
            cnt+=mp[i]-i;
    }
    cout<<cnt<<endl;


    return 0;
}
