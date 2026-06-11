#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    set <string> data;
    int n;
    cin>>n;
    string* a = new string[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    data.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        if( data.find(a[i])!= data.end() )
        {
            cout<<"No";
            return 0;
        }
        else data.insert(a[i]);
        if( a[i-1][a[i-1].length()-1 ]  != a[i][0] )
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}