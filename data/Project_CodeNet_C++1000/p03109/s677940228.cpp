#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))

int main()
{
string s,tmp="",dt="",mm="";

cin >> s;

tmp += s[0];
tmp += s[1];
tmp += s[2];
tmp += s[3];
if(tmp == "2019")
{
    mm += s[5];
    mm += s[6];

    dt += s[8];
    dt += s[9];

    if(mm.compare("04")>0)cout << "TBD" << endl;
    else if(mm.compare("04") == 0)
    {
        //cout << dt.compare("30") << endl;
        if(dt.compare("30") > 0)cout << "TBD" << endl;
        else cout<<"Heisei"<<endl;
    }
    else cout<<"Heisei"<<endl;
}
else if(tmp.compare("2019") > 0)
{
    cout << "TBD" << endl;
}
else cout<<"Heisei"<<endl;

}
