#include<bits/stdc++.h>

#define rep(i,start,n) for(int i=start;i<(int)(n);i++)
#define rrep(i,end,n) for(int i=n-1;i>=end;i--)
#define each(it,v) for(auto it : v)
#define all(v) (v).begin(),(v).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using vpii = vector<Pii>;
using vpll = vector<Pll>;

const ll mod=1e9+7;
const int intINF=INT_MAX;
const ll  longINF=LONG_LONG_MAX;

main()
{
        int n; cin>>n;
        vi a,b(n);
        rep(i,0,n)
        {
                cin>>b[i];
                if(b[i]>i+1)
                {
                        cout<<-1<<endl;
                        return 0;
                }
        }

        vi ans;
        bool f;
        while(b.size()>0)
        {
                f=false;
                rrep(i,0,b.size())
                {
                        if(b[i]==i+1)
                        {
                                ans.push_back(b[i]);
                                b.erase(b.begin()+i);
                                f=true;
                                break;
                        }
                }
                if(!f)
                {
                        cout<<-1<<endl;
                        return 0;
                }
                //each(it,b)cout<<it<<" ";
                //cout<<endl;
        }

        reverse(all(ans));

        each(it,ans)cout<<it<<endl;
}