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
    vector<int> vec(0);
    int n,k,tmp=0,ans=0;cin>>n>>k;
    string s;cin>>s;
    bool flag;if(s[0]=='1')flag=true;else flag=false;
    for(int i=0;i<n;i++){
        if(flag){
            if(s[i]=='1')tmp++;
            else{
                vec.pb(tmp);tmp=1;flag=false;
            }
        }
        else{
            if(s[i]=='0')tmp++;
            else{
                vec.pb(tmp);tmp=1;flag=true;
            }
        }
    }
    vec.pb(tmp);
    tmp=0;int sz=vec.size();
    if(s[0]=='1'){
        if(vec.size()/2<=k)ans=n;
        else{
            for(int i=0;i<2*k+1;i++)tmp+=vec[i];
            ans=max(ans,tmp);
            int pt=2*k+1;
            while(pt+1<sz){
                tmp-=vec[pt-2*k-1]+vec[pt-2*k];
                tmp+=vec[pt]+vec[pt+1];
                ans=max(ans,tmp);
                pt+=2;
            }
            if(s[n-1]=='0'){
                tmp-=vec[pt-2*k-1]+vec[pt-2*k];
                tmp+=vec[pt];
                ans=max(ans,tmp);
            }
        }
    }
    else{
        if((vec.size()+1)/2<=k)ans=n;
        else{
            for(int i=0;i<2*k;i++)tmp+=vec[i];
            ans=max(ans,tmp);
            int pt=2*k;
            bool fi=true;
            while(pt+1<sz){
                if(fi){
                    tmp-=vec[0];
                    fi=false;
                }
                else{tmp-=vec[pt-2*k]+vec[pt-2*k-1];}
                tmp+=vec[pt]+vec[pt+1];
                ans=max(ans,tmp);
                pt+=2;
            }
            if(s[n-1]=='0'){
                tmp-=vec[pt-2*k];
                if(pt-2*k-1>=0)tmp-=vec[pt-2*k-1];
                tmp+=vec[pt];
                ans=max(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}
