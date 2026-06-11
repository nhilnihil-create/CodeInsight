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
    vector<int> vec(100001,1);
    vec[0]=0;vec[1]=0;
    for(int i=2;i<=316;i++){
        if(vec[i]==0)continue;
        for(int j=i*2;j<100001;j+=i){
            vec[j]=0;
        }
    }
    for(int i=100000;i>=2;i--){
        if(vec[i]==0)continue;
        if(vec[(i+1)/2]==0)vec[i]=0;
    }
    for(int i=1;i<100001;i++){
        vec[i]+=vec[i-1];
    }
    int q,left,right;cin>>q;
    for(int i=0;i<q;i++){
        cin>>left>>right;
        cout<<vec[right]-vec[left-1]<<endl;
    }
}
