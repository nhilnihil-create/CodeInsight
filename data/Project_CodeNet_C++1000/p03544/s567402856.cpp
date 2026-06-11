#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int h,w,n,i=0,j,l[1000]={2,1};
    cin >> n;
    if(n==1)
    {
        cout << "1" << endl;
        return 0;
    }
    for(i=2;i<=n;i++)
    {
        l[i]=l[i-1]+l[i-2];
    }
    cout << l[n] << endl;
    return 0;
}
