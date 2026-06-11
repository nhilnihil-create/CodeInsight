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
    string ans="No";
    int a,b,c,d,e,f,g,h,i;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    if(b-a==e-d&&e-d==h-g){
        if(c-b==f-e&&f-e==i-h){
            if(d-a==e-b&&e-b==f-c){
                if(g-d==h-e&&h-e==i-f){
                    ans="Yes";
                }
            }
        }
    }
    cout<<ans<<endl;
}
