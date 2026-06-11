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

struct box
{
    string s;
    int val,i;
};
bool cmp(box &l,box &r)
{
    if(l.s<r.s)
        return 1;
    if(l.s>r.s)
        return 0;
    if(l.val>r.val)
        return 1;
    return 0;

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<box>v;
    for(int i=1; i<=n; i++)
    {
        string s;
        int a;
        cin>>s>>a;
        box t;
        t.s=s;
        t.val=a;
        t.i=i;
        v.push_back(t);
    }
    sort(all(v),cmp);
    for(auto it:v)
    {
        cout<<it.i<<endl;
    }

    return 0;
}
