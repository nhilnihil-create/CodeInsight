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

int main(){
    int n,m;cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    sort(all(vec));
    vector<pair<int,int>> com(m,pair<int,int> {0,0});
    for(int i=0;i<m;i++){
        cin>>com[i].second;
        cin>>com[i].first;
    }
    sort(all(com),greater<pair<int,int>>());
    int i=0;
    lint ans=0;
    bool end=false;
    for(auto p:com){
        int v=p.first;
        int num=p.second;
        while(num>0){
            num--;
            if(i>=n){end=true;break;}
            if(vec[i]<v){
                ans+=v;i++;
            }
            else {end=true;break;}
        }
        if(end)break;
    }
    if(i<n){
        for(i;i<n;i++){
            ans+=vec[i];
        }
    }
    cout<<ans<<endl;
}
