using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define repa(i,a,b) for (int i=a; i<=b; i++)
#define repd(i,b,a) for (int i=b; i>=a; i--)
#define endl "\n"
//debugging
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

const int N = 1e+6+5;
int big = 1e+18+3;
int mod = 1e+9+7;

signed main()
{
    IOS;
        
    int n,k;
    cin>>n>>k;
    map<int,int>cur_freq;
    set<int>taken;
    multiset< pair<int,int> >replacables;

    pair<int,int> ar[n+1];

    repa(i,1,n)
        cin>>ar[i].ss>>ar[i].ff;

    sort(ar+1,ar+1+n);
    reverse(ar+1,ar+1+n);

    int cur_ans = 0;
    int sz;

    repa(i,1,k)
    {
        cur_ans+=ar[i].ff;
        taken.insert(ar[i].ss);
        cur_freq[ar[i].ss]++;
        replacables.insert({ar[i].ff,ar[i].ss});
    }

    sz = taken.size();
    int best = cur_ans + sz*sz;

    repa(i,k+1,n)
    {
        if ( taken.find(ar[i].ss)!=taken.end() )
            continue;

        while(replacables.size())
        {
            auto it = *replacables.begin();

            if ( cur_freq[it.ss]==1 )
                replacables.erase(replacables.find(it));

            else
            {
                replacables.erase(replacables.find(it));
                cur_ans-=it.ff;
                cur_ans+=ar[i].ff;
                cur_freq[it.ss]--;
                cur_freq[ar[i].ss]++;

                sz++;

                taken.insert(ar[i].ss);
                best = max(best,cur_ans+(sz*sz));
                break;
            }
        }
    }

    cout<< best <<endl;
}