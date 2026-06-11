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
int f;
void recur(int n)
{
    if(n==0)
        f=1;
    if(n<=0)
        return ;

    recur(n-4);
    recur(n-7);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
  recur(n);
    if(f)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}
