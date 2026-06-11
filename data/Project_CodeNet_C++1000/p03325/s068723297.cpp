#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,saidai=0,m,n,a[100000];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        while(a[i]%2==0)
        {
            c++;
            a[i]=a[i]/2;
        }
    }
    cout << c << endl;

    return 0;

}
