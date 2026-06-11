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
    int x;
    vector<int> vec(4);
    for(int i=0;i<6;i++){
        cin>>x;vec[x-1]++;
    }
    int cnt=0;
    for(int i=0;i<4;i++){
        if(vec[i]%2==1)cnt++;
    }
    if(cnt==0||cnt==2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
