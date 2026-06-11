#include<bits/stdc++.h>
int a,s,n;using namespace std;bitset<1<<22>d;main(){cin>>n;d|=1;while(cin>>a)s+=a,d|=d<<a;while(!d[++s/2]);cout<<s/2;}