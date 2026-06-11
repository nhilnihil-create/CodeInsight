    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cstring>
    using namespace std;
    typedef long long ll;
    int main()
    {
        ios::sync_with_stdio(false);
        int t;
        cin >>t;
        for(int i=1;i<=t;i++)
            {
                ll a,b,c,d;
                cin >>a>>b>>c>>d;
                if(a<b){cout <<"No"<<endl;continue;}
                if(a>=b&&d>=b&&c>=b){cout <<"Yes"<<endl;continue;}
                if(d<b){cout <<"No"<<endl;continue;}
                if(c>=b)
                    {
                        if(d<b){cout <<"No"<<endl;continue;}
                        else {cout <<"Yes"<<endl;continue;}
                    }
                else 
                    {
                        ll g=__gcd(b,d);
                        if(b-g+a%g>c)
                            {cout <<"No"<<endl;continue;}
                        else {cout <<"Yes"<<endl;continue;}                        
                    }
            }
        return 0;
    }