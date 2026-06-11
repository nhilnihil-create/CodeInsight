#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n ,m ,c;
int main()
{
    cin>>n>>m>>c;

        if(n!=m&&n==c)cout<<m;
        else if(n!=c&&n==m)cout<<c;
        else cout<<n;



    return 0;
}
