#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define lli long long int
#define test                lli t;cin>>t;while(t-->0)
#define ainput  int n;cin>>n;int a[n];for(int i=0;i<n;i++){cin>>a[i];}
#define vec vector<lli>v;
vec
#define avinput  int n;cin>>n;int a[n];for(int i=0;i<n;i++){cin>>a[i];v.push_back(a[i]);}
#define vp  for(lli i=0;i<v.size();i++) {cout<<v[i]<<" ";}cout<<endl;
#define vp1  for(lli i=0;i<v1.size();i++) {cout<<v1[i]<<" ";}cout<<endl;
#define vp2  for(lli i=0;i<v2.size();i++) {cout<<v2[i]<<" ";}cout<<endl;
#define vp3  for(lli i=0;i<v3.size();i++) {cout<<v3[i]<<" ";}cout<<endl;
#define vp6  for(lli i=0;i<v6.size();i++) {cout<<v6[i].first<<" "<<v6[i].second<<endl;}
#define ln cout<<endl;
  //cout << fixed << setprecision(10) <<((double)((sum*1.0)/((n*1.0-k*1.0)+1.0))) << endl;
set<lli>s1;
set<lli>s2;
set<string>st2;
vector<lli>v1;
vector<lli>v2;
vector<lli>v3;
vector<lli>v4;
vector<lli>v5;
vector<pair<lli,lli> >v6;
vector<pair<char,int> >v16;
vector<string>v7;
vector<string>v8;
vector<char>v9;
vector<double>v11;
list<lli>l;
//****coding start****
int main()
{
lli n;cin>>n;
lli a[n],b[n];
for(lli i=0;i<n;i++){
    cin>>a[i];
}
for(lli i=0;i<n;i++){
    cin>>b[i];
}
for(lli i=0;i<n;i++){
    v6.push_back(make_pair(a[i]-b[i],i));
}
sort(v6.begin(),v6.end());
reverse(v6.begin(),v6.end());
lli m=0;
lli sum1=0,sum2=0;
for(lli i=0;i<v6.size();i++){
        sum1=sum1+a[v6[i].second];
sum2=sum2+b[v6[i].second];
    m=max(m,sum1-sum2);
}
cout<<m<<endl;
    return 0;
}