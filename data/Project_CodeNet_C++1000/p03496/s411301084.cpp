#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK: 2000000")

using namespace std;

const int N = 2e6 + 5;

long long n , a[N] , b[N];
vector< pair<long long , long long> > ans , ans2;

int main() {
    cin>>n;
    long long mx =-1e12 , mn = 1e12 , idx = -1 , idx2 = -1;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>mx)
        {
            mx = a[i];
            idx = i;
        }
        if(a[i]<mn)
        {
            mn = a[i];
            idx2 = i;
        }
    }

    for(int i = 0;i<22;i++)
    {
        bool ok = 1;
        ans.clear();
        for(int j = 0;j<n;j++)
            b[j] = a[j];
        mx = a[idx];
        for(int j = 0;j<i;j++)
        {
           mx*=2;
           ans.push_back({ idx+1,idx+1 });
        }
        b[idx] = mx;
        for(int j= 1;j<n;j++)
        {
            while(ok && b[j]<b[j-1])
            {
                b[j]+=mx;
                ans.push_back({idx+1 ,j+1 });
                if( b[j] >mx )
                {
                    mx = b[j];
                    idx = j;
                }
                if(ans.size()>n*2)
                    ok = 0;
            }
        }
        if(ok && ans.size()<=2*n)
        {
            cout<<ans.size()<<"\n";
            for(auto u : ans)
                cout<<u.first<<" "<<u.second<<"\n";
            return 0;
        }
    }

    for(int i = 0;i<22;i++)
    {
        bool ok = 1;
        ans.clear();
        for(int j = 0;j<n;j++)
            b[j] = a[j];
        mn = a[idx2];
        for(int j = 0;j<i;j++)
        {
            ans.push_back({ idx2+1,idx2+1 });
            mn*=2;
        }
        b[idx2] = mn;
        for(int j=n-2;j>=0;j--)
        {
            while(ok && b[j]>b[j+1])
            {
                b[j]+=mn;
                ans.push_back({idx2+1 ,j+1 });
                if(ans.size()>n*2)
                    ok = 0;
                if( b[j] <mn )
                {
                    mn = b[j];
                    idx2 = j;
                }
            }
        }
        if(ok && ans.size()<=2*n)
        {
            cout<<ans.size()<<"\n";
            for(auto u : ans)
                cout<<u.first<<" "<<u.second<<"\n";
            return 0;
        }
    }
    return 0;
}
