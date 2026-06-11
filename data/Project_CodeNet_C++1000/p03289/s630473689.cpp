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
    string s;
    cin>>s;
    if(s[0]!='A')
        cout<<"WA"<<endl;
    else
    {
        map<int,int>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;
        int f=0;
        for(int i='A'; i<='Z'; i++)
        {
            if(i=='A' || i=='C')
                continue;
            if(mp[i])
                f=1;
        }
        if(f)
            cout<<"WA"<<endl;
        else
        {
            mp.clear();
            for(int i=2; i<s.length()-1; i++)
                mp[s[i]]++;
            if(mp['C']==1)
                cout<<"AC"<<endl;
            else
                cout<<"WA"<<endl;
        }
    }
    return 0;
}
