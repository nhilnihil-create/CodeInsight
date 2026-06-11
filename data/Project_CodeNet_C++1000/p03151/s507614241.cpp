#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n,x,ans=0;cin>>n;
    vector<int> a(n),b(n);
    lint asum=0,bsum=0,fusoku=0;
    for(int i=0;i<n;i++){cin>>x;a[i]=x;asum+=x;}
    for(int i=0;i<n;i++){cin>>x;b[i]=x;bsum+=x;}
    if(asum<bsum){cout<<-1<<endl;return 0;}
    vector<int> zaiko(0);
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){ans++;fusoku+=b[i]-a[i];}
        else zaiko.pb(a[i]-b[i]);
    }
    sort(all(zaiko),greater<int>());
    int pointer=0;
    while(fusoku>0){
        fusoku-=zaiko[pointer];
        pointer++;ans++;
    }
    cout<<ans<<endl;
}
