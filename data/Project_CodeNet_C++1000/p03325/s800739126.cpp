        #include<bits/stdc++.h>
        #define ll long long
        #define rep(i,a,b) for(i=a;i<b;i++)
        #define pb push_back
        #define all(v) v.begin(),v.end()
        #define F first
        #define S second
        #define hell 1000000007
        using namespace std;
        const int N=500;
        void solve()
        {
            ll i,j,k,n,m,c=0,ans=0;
            string s;
            cin>>n;
            rep(i,0,n)
            {
                cin>>k; c=0;
                while(k%2==0)
                {
                    k/=2;
                    c++;
                }
                ans+=c;
            }
cout<<ans;



    }

        int main()
        {
            ios::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            int t=1;
            //cin>>t;
            while(t--)
            solve();
        }
