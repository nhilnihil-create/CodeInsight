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

lint ruiseki_xor(lint x){
    if(x%4==0)return x;
    if(x%4==1)return 1;
    if(x%4==2)return x+1;
    if(x%4==3)return 0;
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    lint a,b;cin>>a>>b;
    lint ans=ruiseki_xor(a-1)^ruiseki_xor(b);
    cout<<ans<<endl;
}
