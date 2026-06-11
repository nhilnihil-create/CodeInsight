#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define all(v) v.begin(),v.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    fast ;
    int n,c=0,i,t;
    cin >> t ;
    vector<int>v(t);
    for(auto &x:v)
        cin >> x ;
    for(i=0 ; i<t ; i++)
    {
        cin >> n;
        if(v[i]-n>0)
            c=c+v[i]-n;
    }
    cout << c << "\n";
    return 0;
}
