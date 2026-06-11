#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>

int main(void)
{
    int n,m;
    cin>>n>>m;
    int maxi = 100006;
    int mini = -1;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        maxi = min(maxi,b);
        mini = max(mini,a);

    }

    if(maxi<mini)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<maxi-mini+1<<endl;
}