#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string>
#define pll pair<ll,ll>
#define NMAX 200001

using namespace std;
typedef long long ll;
typedef long double ld;
int val[NMAX];
int main()
{
    ios::sync_with_stdio(false);
    int H,W,n,x,y;
    string s,t;
    cin>>H>>W>>n>>x>>y;
    cin>>s>>t;
    int vact;
    char act[]={'R','L','U','D'};
    char op[] ={'L','R','D','U'};
    int valact[]={W-y+1,y,x,H-x+1};
    int maxact[]={W,W,H,H};
    for(int car=0;car<4;car++)
    {
        for(int i=n-1;i>=0;i--)
        {
            val[i]=val[i+1]+(s[i]==op[car])-(t[i]==act[car]);
        }
        vact=valact[car];
        for(int i=0;i<n;i++)
        {
            if(s[i]==act[car])
            {
                vact--;
            }
            if(vact<=0)
            {
                cout<<"NO"<<'\n';
                return 0;
            }
            if(t[i]==op[car] && vact+1<=maxact[car])
            {
                vact++;
            }
            else
            {
                if(t[i]==act[car] && maxact[car]-vact-val[i]+1<=0)
                    vact--;
            }
            if(vact<=0)
            {
                cout<<"NO"<<'\n';
                return 0;
            }
        }
        if(vact<=0)
        {
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    return 0;
}