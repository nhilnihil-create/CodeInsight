#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
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
    int n;cin>>n;
    int t,a,memo;cin>>t>>a;
    double best=1000000;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        double tmp=t-x*0.006;
        if(abs(tmp-a)<best){
            best=abs(tmp-a);
            memo=i;
        }
    }
    cout<<memo<<endl;
}
