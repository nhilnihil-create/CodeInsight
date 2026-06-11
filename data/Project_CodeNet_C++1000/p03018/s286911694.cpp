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
    string s;cin>>s;
    int sz=s.size();
    lint ans=0,tmp=0;
    for(int i=sz-1;i>=0;i--){
        if(s[i]=='C'&&i-1>=0){
            if(s[i-1]=='B'){
                tmp++;i--;
            }
            else tmp=0;
        }
        else if(s[i]=='A'){
            ans+=tmp;
        }
        else tmp=0;
    }
    cout<<ans<<endl;
}
