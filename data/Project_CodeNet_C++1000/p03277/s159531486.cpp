    #include <bits/stdc++.h>
    #define mp make_pair
    #define f1 first
    #define f2 second
    #define pb push_back
    #define pii pair<int ,int>
    #define ios  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long
    using namespace std;
    const int mox=1e5+9;
    int na[mox];
    int ma[mox];
    vector<pii> g;
    int tree[mox];
    int n;
    void add(int id)
    {
     for(int i=id ; i<=n ; i+=(i&(-i)))
            tree[i]+=1;
    }
    int get(int id)
    {
        int ans=0;
        for(int i=id ; i>0 ; i-=(i&(-i)))
            ans+=tree[i];
        return ans;
    }
    main()
    {
        ios
        cin>>n;
        for(int i=0 ; i<n ; i++)
            cin>>na[i];
        int low=1;
        int hi=1e9+1;
        int u=((((n*(n+1))/2)+1)/2);
        while(low<hi-1)
        {
            int mid=(low+hi)/2;
            int x=0;
            int ans=0;
            for(int i=1 ; i<=n ; i++)
            {
                if(na[i-1]>=mid)
                    x++;
                ma[i]=((2*x)-i);
                g.pb({ma[i],i});
                if(ma[i]>=0)
                    ans++;
            }
            sort(g.begin(),g.end());
            for(int i=0 ; i<n  ; i++)
            {
                 ans+=get(g[i].f2);
                 add(g[i].f2);
            }
           g.clear();
           memset(tree,0,sizeof(tree));
            if(ans>=u)
            {
                low=mid;
            }
            else
                hi=mid;
        }
        cout<<low;


    }
