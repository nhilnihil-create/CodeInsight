#include<bits/stdc++.h>
#define fr(i,j,n)   for(int i=j;i<n;i++)
#define pb          push_back
#define rf(i,j,p)   for(int i=p;i>=j;i--)
#define vi          vector<int>
#define vll         vector<long long>
#define ll          long long
#define hmm         "\n"
#define sp          " "
#define srt(v)      sort(v.begin(), v.end());
#define down        cout<<hmm;
#define faaast      ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
int main()
{
 string s ; cin >> s ;  vi v ;
 fr(i,0,s.size())
 {
     if(s[i]=='W')v.pb(i+1);
 }
 ll sum=0;
 fr(i,0,v.size())
 {
     sum+=v[i];
 }
ll n = v.size();
sum-=n*(n+1)/2;
cout<<sum<<hmm;
// return main();
}