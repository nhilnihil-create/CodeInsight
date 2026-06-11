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
     int n,k;
     cin>>n>>k;
     vector<int>v;
     for(int i=0;i<n;i++)
     {
         int a;
         cin>>a;
         v.push_back(a);
     }
     sort(all(v));
     int mx=INT_MAX;
     for(int i=0;i<=n-k;i++){
        int cur=v[i+k-1]-v[i];
        mx=min(mx,cur);
     }
     cout<<mx<<endl;



    return 0;
}
