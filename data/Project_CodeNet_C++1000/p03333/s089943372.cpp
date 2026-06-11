#include <iostream>
#include <algorithm>

using namespace std;

int st[100005],dr[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>st[i]>>dr[i];
    sort(st,st+n+1);
    sort(dr,dr+n+1);
    long long sol=0;
    for(int i=0;i<=n;i++)
    {
        if(dr[i]>=st[n-i])
            break;
        sol+=st[n-i]-dr[i];
    }
    cout<<sol*2;


    return 0;
}
