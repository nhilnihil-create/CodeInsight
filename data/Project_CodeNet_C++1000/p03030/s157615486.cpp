#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int tc; cin>>tc; while(tc--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    int n, t;
    string s;
    cin>> n;

    vector < std::tuple < string, int, int > > v;

    for(int i=0; i<n; i++)
    {
        cin>> s>> t;
        v.push_back(std::tuple<string,int,int>(s, 100- t, i+1));
    }

    sort (v.begin(), v.end());

    for ( const auto& i : v )
        cout << get<2>(i) << '\n';
    


    return 0;
}