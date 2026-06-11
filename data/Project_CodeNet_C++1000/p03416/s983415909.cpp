#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
#define test     int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;
vector<int>node[10001];

int main()
{


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

        int n,m;
        cin>>n>>m;
        string s;
        int ans=0;
        for(int i=n;i<=m;i++)
        {
            s=to_string(i);
            int flag=1;
            int k=s.size();
            for(int i=0;i<k/2;i++)
            {
                if(s[i]!=s[k-i-1])
                    flag=0;
            }
            if(flag)
                ans++;

        }
        cout<<ans<<endl;



      return 0;

 }