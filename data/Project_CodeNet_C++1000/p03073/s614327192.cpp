
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
  string s ; cin >> s ;
  string t="", tt="" ;
  fr(i,0,s.size())
  {
      if(i%2==0)t+="0";
      else t+="1";
  }
  fr(i,0,s.size())
  {
      if(i%2==0)tt+="1";
      else tt+="0";
  }
  int a1=0, a2=0;
  fr(i,0,s.size())
  {
      if(t[i]!=s[i])a1++;
      if(tt[i]!=s[i])a2++;
  }
  cout<<min(a1,a2)<<hmm;
}
