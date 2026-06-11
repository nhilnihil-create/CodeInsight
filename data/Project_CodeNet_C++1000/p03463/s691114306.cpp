#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin>>n>>a>>b;
    if(a%2==0 && b%2==0 || a%2==1 && b%2==1)
        cout<<"Alice";
    else if(a%2==1 && b%2==0 || a%2==0 && b%2==1)
        cout<<"Borys";
    else
        cout<<"Draw";
}
