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


    int mn= 1000;

    for(int i=0; i<s.size()-2; i++)
       mn= min (mn, abs(753-(  ((s[i]- '0') *100 )+((s[i+1]- '0')* 10 )+ ((s[i+2]- '0')) ) ) );


    cout << mn;
    nl;


    return 0;
}

