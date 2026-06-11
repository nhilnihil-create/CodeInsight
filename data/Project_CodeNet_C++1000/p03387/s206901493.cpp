#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a[3],i;
    for(i=0;i<3;i++)
    {
        cin >> a[i];
    }
    sort(a,a+3,greater<int>());
    if(a[1]%2!=a[2]%2)
    {
        cout << ((a[0]-a[1])+(a[0]-a[2]))/2+2 << endl;
    }
    else
    {
        cout << ((a[0]-a[1])+(a[0]-a[2]))/2 << endl;
    }
    return 0;

}
