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
    string x;cin>>x;
    bool kurisagari=false;
    int ans=0;
    for(int i=0;i<x.size();i++){
        if(i==0)ans+=x[i]-'0';
        else{
            if(x[i]!='9'){
                if(kurisagari)ans+=9;
                else{
                    kurisagari=true;
                    ans+=8;
                }
            }
            else ans+=9;
        }
    }
    cout<<ans<<endl;
}
