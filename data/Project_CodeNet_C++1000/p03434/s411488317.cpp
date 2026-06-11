#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,b,i,j,v=0,a[100010],ans=0,bob=0,alice=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    for(i=0;i<n;i++)
        if(i%2==0)
        {
            alice+=a[i];
        }
        else
        {
            bob+=a[i];
        }
    ans=alice-bob;
    cout << ans << endl;

    return 0;

}
