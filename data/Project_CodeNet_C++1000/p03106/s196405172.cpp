#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,k,i=0,j,c=0,p,h[1000010];
    cin >> a >> b >> k;
    for(i=max(a,b);i>0;i--)
    {
        if(a%i==0 && b%i==0)
        {
            c++;
        }
        if(c==k)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;

}
