#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int sum=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='2')
        {
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}