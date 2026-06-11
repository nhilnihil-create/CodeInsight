#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)


int main()
{
    int a,b,k;cin>>a>>b>>k;
    int i = 0;
    while(true){
        a /= 2;
        b += a;
        i++;
        if(i == k) break;
        b /= 2;
        a += b;
        i++;
        if(i == k) break;
    
    }
    cout << a << " " << b << endl;
}