#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t;
     map<string,ll>mp;
     cin>>t;
     t--;
     string str;
     cin>>str;
     char ch=str[str.size()-1];
     mp[str]++;
     ll cnt=0;
     while(t--)
     {
         cin>>str;
         if(str[0]!=ch || mp[str]>0)
            cnt=10;
         ch=str[str.size()-1];
         mp[str]++;
     }
     if(cnt==10)
        cout<<"No"<<endl;
     else
        cout<<"Yes"<<endl;
}

