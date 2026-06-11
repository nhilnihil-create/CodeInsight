#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,point;
    string shop_name;
    cin>>n;

    pair<pair<string,int>,int> data[n];
    for(i = 0; i < n; i++)
    {
        cin>>shop_name>>point;
        data[i] = make_pair(make_pair(shop_name,-point),i);
    }
    sort(data,data+n);

    for(i = 0; i < n; i++)
    {
        cout<<data[i].second+1<<endl;
    }
}