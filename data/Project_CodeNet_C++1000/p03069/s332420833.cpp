//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll i,j,n,k,cnt=0,ans;
    string s;
    cin>>n>>s;
    for(auto c:s)
    {
        if(c=='.')
       cnt++;
    }
    ans=cnt;
    for(auto c:s)
    {
        if(c=='.') cnt--;
        else cnt++;
        ans=min(ans,cnt);
    }
    cout<<min(ans,cnt)<<endl;



    return 0;
}



