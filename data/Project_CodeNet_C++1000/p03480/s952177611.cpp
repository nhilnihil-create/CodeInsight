#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int,int> pa;
const int N = 2e5+100;
char s[N];
int ans;
void solve()
{
   cin>>s+1;
   int len=strlen(s+1);
  // cout<<len<<endl;
   ans=len/2;
   while(1){
     int l=len-ans+1,r=ans;
     for(int i=l;i<r;i++)
        if((s[i]-'0')^(s[i+1]-'0')) return ;
        ans++;
   // if(ans==len) break;
   }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    cout<<ans-1<<endl;
    return 0;
}
