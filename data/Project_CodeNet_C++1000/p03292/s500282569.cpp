#include<bits/stdc++.h>
using namespace std;
#define v  vector<int>
#define pb  push_back

int a,b,c;

int main()
{
    cin>>c>>b>>a;
    cout<<abs(a-b)+abs(b-c)+abs(a-c)-max(max(abs(a-b),abs(b-c)),abs(a-c));
}
