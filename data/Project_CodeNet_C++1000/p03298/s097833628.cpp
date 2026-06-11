#include<bits/stdc++.h>

using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(x, l, r)            for (LL x = l; x<=r; ++x)
#define REP(x,r)               for (LL x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";

//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//

LL n;
string s;

unordered_map<string , LL> mp;

void func(LL pos)
{
        if(pos==n)
        {
                string t;
                for(LL i=0;i<n;i++)
                {
                        if(s[i]>='a'&&s[i]<='z') t+=s[i];
                }
                for(LL i=0;i<n;i++)
                {
                        if(s[i]>='A'&&s[i]<='Z') t+=s[i];
                }

                mp[t]++;

                return;
        }

        func(pos+1);
        s[pos] += 'A' - 'a';
        func(pos+1);
        s[pos] -= 'A' -'a';

}


LL ans;

void func2(LL pos)
{
        if(pos==n)
        {

                string t;
                for(LL i=0;i<n;i++)
                {
                        if(s[i]>='a'&&s[i]<='z') t+=s[i];
                }
                for(LL i=0;i<n;i++)
                {
                        if(s[i]>='A'&&s[i]<='Z') t+=s[i];
                }

                ans+=mp[t];



                return;
        }

        func2(pos+1);
        s[pos] += 'A' - 'a';
        func2(pos+1);
        s[pos] -= 'A' -'a';

}


int main()
{

        cin>>n;
        cin>>s;

        func(0);
        reverse(all(s));

        func2(0);

        cout<<ans;

        //cout<<s;

}
