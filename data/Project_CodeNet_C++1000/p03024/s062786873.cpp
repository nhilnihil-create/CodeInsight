#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

char score[15];

main()
{
        rep(i,15)score[i]='o';
        string s; cin>>s;
        int n=s.size();
        rep(i,n)score[i]=s[i];
        int cnt=0;
        rep(i,15)cnt+=score[i]=='o';
        if(cnt>=8)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}