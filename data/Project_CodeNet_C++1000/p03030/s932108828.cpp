#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define mp make_pair
#define pb push_back
bool sortbysec(const pair<string,int>&a,pair<string,int>&b)
{
    return (a.second>b.second);
}
pair<pair<string,int>,int>pa[120];
int main()
{
    int n;
    cin>>n;
    int i=0,a=n;
    while(n--)
    {
        string s;
        int p;
        cin>>s>>p;
        pa[i]=make_pair(make_pair(s,-p),i+1);
        i++;
    }
    sort(pa,pa+a);
    for(int i=0;i<a;i++)
        cout<<pa[i].second<<endl;
}

