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
    vector<string>v;
    for(int i=1; i<=9; i++)
    {
        string temp="0";
        temp+=(i+48);
        v.push_back(temp);
    }
    v.push_back("10");
    v.push_back("11");
    v.push_back("12");
    int cnt=0,x=0,y=0;
    for(int i=0; i<12; i++)
    {
        if(s[0]==v[i][0] && s[1]==v[i][1])
            x=1;
    }
    for(int i=0; i<12; i++)
    {
        if(s[2]==v[i][0] && s[3]==v[i][1])
            y=1;
    }
    if(x && y)
    {
        cout<<"AMBIGUOUS"<<endl;
    }
    else if(x)
        cout<<"MMYY"<<endl;
    else if(y)
        cout<<"YYMM"<<endl;
    else
        cout<<"NA"<<endl;


    return 0;
}
