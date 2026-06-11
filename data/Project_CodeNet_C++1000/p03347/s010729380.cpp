// /*
//ID: C4551DY
//TASK: friday
//LANG: C++14
//*/
/*  CF_CC
        4U7H0R:_C4551DY */

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define IC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(ia) for(int i=0;i<a;i++)
#define lb lower_bound
#define ll long long
#define pii pair<int,int>
#define vec vector<ll>
#define fir first
#define sec second
#define pb push_back
const int mxi=1e6+7;
const int mod=1e9+7;

ll a,ans;

int main()
{
    IC
    //ofstream cout ("-_-.out");
    //ifstream cin ("-_-.in");
    cin >> a;
    int n[a] ;
    for(int i=0;i<a;i++){
        cin >> n[i] ;
    }
    for(int i=0;i<a;i++)
        if (i<n[i]){
            cout << -1;
            return 0;
    }
    for (int i=1;i<a;i++){
        if (n[i]!=n[i-1]+1){
            if (n[i]>n[i-1]+1){
                cout << -1;
                return 0;
            }
            ans+=n[i-1] ;
        }
    }
    ans+=n[a-1];
    cout << ans ;
}

