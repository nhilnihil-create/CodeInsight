//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,x;
    string s;
    //set + string Lexi_sort succesfully
    pair<pair<string,ll>,ll>restu[150];
    cin>>t;
    for(i=0;i<t;i++){
    cin>>s>>x;
    restu[i]=make_pair(make_pair(s,-x),i+1);
    }
    sort(restu,restu+t);
    for(i=0;i<t;i++){

        cout<<restu[i].second<<endl;

    }


    return 0;
}



