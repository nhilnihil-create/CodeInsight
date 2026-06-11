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
    int n,a,b;cin>>n>>a>>b;
    string tmp;
    int ans=0;
    for(int i=1;i<=n;i++){
        tmp=str(i);int sum=0;
        for(char c:tmp)sum+=c-'0';
        if(a<=sum&&sum<=b)ans+=i;
    }
    cout<<ans<<endl;
}
