    #include <iostream>
    #include <bits/stdc++.h>
     
    using namespace std;
    const int maxn = 4;
    typedef long long ll;
    const int INF = 1e9+7;
     
    list<int>sta[maxn];
    void action()
    {   //cout<<sqrt(880)<<endl;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
     
     
            ll cnt = a*b;
     
            if(a==b)
            {
                cout<<2*a-2<<endl;
                continue;
                
            }
            
            ll sq = sqrt(cnt);
            ll sq1 = sq;
            ll sq2 = sq;
            if(a<=sq)
            {
                sq1--;
                sq2--;
            }
            if(b<=sq)
            {
                sq1--;
                sq2--;
            }
            if(sq*sq==cnt)
                sq1--;
     
            ll cnt22 = ceil(sqrt(cnt));
            if(cnt22 * sq <cnt )
                sq1++;
            printf("%lld\n",sq1+sq2);
     
        }
     
    }
    int main()
    {
     
        action();
        return 0;
    }