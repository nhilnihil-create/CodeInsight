#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int n;cin>>n;
    string ans="Yes";
    int tx=0,ty=0,tt=0,t,x,y;
    for(int i=0;i<n;i++){
        cin>>t>>x>>y;
        if(abs(tx-x)+abs(ty-y)>t-tt){
            ans="No";break;
        }
        if((x+y)%2!=t%2){
            ans="No";break;
        }
        tx=x;ty=y;tt=t;
    }
    cout<<ans<<endl;
}
