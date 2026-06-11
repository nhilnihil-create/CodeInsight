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
int freq[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
     int n,m;
     cin>>n>>m;
     for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        freq[a]++;
        freq[b+1]--;
     }
     int cnt=0;
     for(int i=1;i<=n;i++){
        freq[i]+=freq[i-1];
        if(freq[i]==m)
            cnt++;
     }
     cout<<cnt<<endl;

    return 0;
}
