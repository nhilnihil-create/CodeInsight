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
    int a,b,c,d=0;
    cin>>a>>b>>c;
    vector<int>v;
    for(int i=1; i<=1000; i++)
    {
        if(a%i==0 && b%i==0)
        {
            v.push_back(i);
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        c--;
        if(c==0){
            cout<<v[i]<<endl;
            return 0;
        }
    }

    return 0;
}
