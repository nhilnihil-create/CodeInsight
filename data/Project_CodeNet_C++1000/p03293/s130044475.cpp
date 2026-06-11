#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    string a, b;
    cin>> a>> b;

    string s= a, t= b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    if(a!= b)
    {
        cout<<  "No\n";
        return 0;
    }

    int n= a.size();
    for(int i=0; i<n; i++)
    {
        if(s==t)
        {
            cout<<  "Yes\n";
            return 0;
        }
        s=s[n-1]+ s;
        s.pop_back();

    }
    cout<<  "No\n";

    return 0;
}


