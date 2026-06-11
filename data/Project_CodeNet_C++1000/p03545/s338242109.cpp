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
ll arr[MAX];
string s;
void recur(int pos,vector<char>v,int sum)
{
    if(pos==4)
    {
        if(sum==7)
        {
            cout<<s[0]<<v[0]<<s[1]<<v[1]<<s[2]<<v[2]<<s[3]<<"=7"<<endl;
            exit(0);
        }
        return;
    }
    v.push_back('+');
    recur(pos+1,v,sum+(s[pos]-48));
    v.pop_back();
    v.push_back('-');
    recur(pos+1,v,sum-(s[pos]-48));

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    cin>>s;
    vector<char>v;
    recur(1,v,s[0]-48);
    return 0;
}
