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
    vector<int> vec(10);
    for(int i=0;i<4;i++){
        cin>>x;
        vec[x]++;
    }
    if(vec[1]==1&&vec[4]==1&&vec[7]==1&&vec[9]==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
