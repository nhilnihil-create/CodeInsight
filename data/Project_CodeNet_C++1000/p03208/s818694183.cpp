#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j=0,c=0,n,k,m=99999999999,h[100000],a;
    string s;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    sort(h,h+n);
    for(i=0;i<=n-k;i++)
    {
        if(m>h[i+k-1]-h[i])
        {
            m=h[i+k-1]-h[i];
        }
    }
    cout << m << endl;
    return 0;

}
