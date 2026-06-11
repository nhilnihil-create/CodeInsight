#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> v{0,111,222,333,444,555,666,777,888,999};
int main()
{
    string s;
    cin>>s;
    for(char c:s) if(c=='1') cout<<9;else if(c=='9') cout<<1;else cout<<c;
    cout<<endl;
}