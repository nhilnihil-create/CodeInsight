#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/
int main()
{
     ll n;
     cin>>n;
     string str;
     cin>>str;
     ll mx=0;
     for(int i=0;i<n-1;i++)
     {
         ll cnt=0,arr[26],arr2[26];
         for(int k=0;k<26;k++)
             arr[k]=0,arr2[k]=0;
         for(int k=0;k<=i;k++)
             arr[str[k]-'a']++;
         for(int k=i+1;k<n;k++)
             arr2[str[k]-'a']++;
         for(int k=0;k<26;k++)
             if(arr[k]>0 && arr2[k]>0)
                cnt++;
         mx=max(mx,cnt);
     }
     cout<<mx<<endl;
}

