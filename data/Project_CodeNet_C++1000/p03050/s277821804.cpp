//#define _GLIBCXX_DEBUG
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
    lint n,x;cin>>n;
    priority_queue<lint> yakusuu;
    for(lint i=1;i<=sqrt(n);i++){
        if(n%i==0){
            yakusuu.push(i);
            yakusuu.push(n/i);
        }
    }
    lint ans=0;
    while(!yakusuu.empty()){
        x=yakusuu.top();yakusuu.pop();
        if(x-1>n/x)ans+=x-1;
        else break;
    }
    cout<<ans<<endl;
}