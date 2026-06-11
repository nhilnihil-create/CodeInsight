#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
set<string>st;
int k,len;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>s;
    cin>>k;
    len=s.length();
    for(int i='a'; i<='z'; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(s[j]==i)
            {
                string sub;
                int it=j,k=0;
                while(it<len && k<5){
                    sub+=s[it];
                    k++;
                    st.insert(sub);
                    it++;
                }
            }
        }
    }
    for(auto x:st)
    {
        k--;
        if(!k)
        {
            cout<<x<<endl;
            return 0;
        }

    }

    return 0;
}
