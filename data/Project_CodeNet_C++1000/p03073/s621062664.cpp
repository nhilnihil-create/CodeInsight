#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
 
#define mx(ans, cnt) ans = max(ans, cnt)
#define fauto(a) for(auto i : a) cout << i << " "; cout << endl;
#define sp(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define _ << " " <<
#define swp(x, y) if (x > y) swap(x, y);
#define swpg(x, y) if (x < y) swap(x, y);
#define ff first
#define ss second
#define xx first
#define yy second
#define pb push_back
#define nn end1
 
 
using ll = long long;
using ull = unsigned long long;
using namespace std;
int main ()
{
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll i,j,c=0,n;
        string s;
        cin>>s;
        n=s.size();
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                if(s[i]=='1')
                {s[i+1]='0';}
                else
                {
                    s[i+1]='1';
                }
                c++;
            }

        }
       cout<<c<<endl;   
    }
    return 0;
}