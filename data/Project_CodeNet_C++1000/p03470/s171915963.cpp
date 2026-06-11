#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,b,i,j,v=0,d[100010],saisyou=10000,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> d[i];
    }
    sort(d,d+n,greater<int>());
    for(i=0;i<n;i++)
    {
        if(d[i]<saisyou)
        {
            saisyou=d[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;

}
