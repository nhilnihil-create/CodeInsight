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
    string x,y;
    cin>>x>>y;
    int mx=0,l1=x.length(),l2=y.length();
    if(l1<l2)
        cout<<"UNRESTORABLE"<<endl;
    else
    {
        int pos=-1,mx=0;
        for(int i=0; i<=l1-l2; i++)
        {
            int cnt=0,f=1;
            for(int j=0; j<l2; j++)
            {
                if(x[i+j]==y[j])
                {
                    cnt++;
                }
                else if(x[i+j]!='?')
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                if(mx!=l2)
                {
                    pos=i;
                    mx=cnt;
                }

            }
        }
        if(pos==-1)
            cout<<"UNRESTORABLE"<<endl;
        else
        {
            for(int i=pos,j=0; j<l2; j++,i++)
                x[i]=y[j];
            for(int i=0; i<l1; i++)
                if(x[i]=='?')
                    x[i]='a';
            cout<<x<<endl;
        }
    }



    return 0;
}
