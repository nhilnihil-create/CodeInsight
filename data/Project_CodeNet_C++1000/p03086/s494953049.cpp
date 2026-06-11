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

    string s;
    cin>> s;

    int mx= 0, c=0;

    for(int i=0; i<s.size(); i++)
    {
        if( s[i]== 'C' || s[i]== 'T' || s[i]== 'A' || s[i]== 'G')
            c++;

        else
        {
            mx= max(mx, c);
            c= 0;
        }
    }

    cout << max ( mx, c);
    nl;

    return 0;
}


