    #include <bits/stdc++.h>
    using namespace std;
    #define all(x) (x).begin(), (x).end()
    #define SZ(X) ((int)(X).size())
    #define mod 10000007
    #define endl "\n"
    typedef unsigned long long ull;
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        // freopen("input.txt", "r", stdin);
        int l,n,m=0,sum=0;;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>l;
            m=max(m,l);
            sum+=l;
        }
         
        if(m<sum-m) cout<<"Yes"<<endl; else cout<<"No"<<endl;
        return 0;

    }

