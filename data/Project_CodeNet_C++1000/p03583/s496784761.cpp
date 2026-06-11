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
    lint n;cin>>n;
    for(lint i=1;i<=3500;i++){
        for(lint j=i;j<=3500;j++){
            lint tmp=n*i*j,tmp2=4*i*j-n*j-n*i;
            if(tmp2!=0){
                if(tmp%tmp2==0){
                    if(tmp/tmp2>0){
                        cout<<i<<" "<<j<<" "<<tmp/tmp2<<endl;
                        return 0;
                    }
                }
            }
        }
    }
}
