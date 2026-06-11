#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
  fast_io
    ll a,b,j;
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(s<t)
    cout<<"Yes"<<endl;

   else  cout<<"No"<<endl;
    return 0;
}



