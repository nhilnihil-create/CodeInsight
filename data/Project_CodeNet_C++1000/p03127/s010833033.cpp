#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long


int main() {
 int t;
 cin>>t;
ll ar[t+5];
REP(i,t)
{
    cin>>ar[i];
}
sort(ar,ar+t);int i=0;
while(1)
{ if(ar[t-1]==1){cout<<1<<endl;return 0;}
    sort(ar,ar+t);
   if(i==t-1) break;
   while(ar[i]==0) i++;
   if(i==t-1) break;
 for(int j=i+1;j<t;j++)
 {ar[j]%=ar[i];
 
 if(ar[j]==1) {cout<<1<<endl;return 0;}
}
}
cout<<ar[t-1]<<endl;
}