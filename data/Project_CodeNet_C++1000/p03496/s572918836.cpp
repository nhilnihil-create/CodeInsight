#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(a) cout << #a << ": " << a << endl
#define sz(a) int(a.size())
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define fast cin.tie(0); ios::sync_with_stdio(false)
#define int long long
vector<pair<int, int>> ans;
int A[51];
int32_t main(){ fast;
	
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>A[i];
    int mi = 0, ma = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(A[mi]>A[i])
            mi = i;
        if(A[ma]<A[i])
            ma = i;
    }
    if(ma && abs(A[ma])>=abs(A[mi]))
    {
        for(int i = 2; i <= n; ++i)
        {
            while(A[i]<A[i-1])
            {
                A[i] += A[ma];
                ans.emplace_back(ma, i);
                if(A[i]>A[ma])
                    ma = i;
            }
        }
    }
    else if(abs(A[mi])>A[ma])
    {
        for(int i = n-1; i >= 1; --i)
        {
            while(A[i]>A[i+1])
            {
                A[i] += A[mi];
                ans.emplace_back(mi, i);
                if(A[i]<A[mi])
                    mi = i;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i: ans)
        cout<<i.first<<' '<<i.second<<endl;
}
