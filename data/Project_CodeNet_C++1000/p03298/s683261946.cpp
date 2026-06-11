#include <iostream>
#include <map>
using namespace std;
typedef pair<string, string> P;
typedef long long ll;
map<P, ll> p,q;
int main(void){
    int n;
    ll m=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<(1<<n);i++){
        string a="",b="",c="",d="";
        for(int j=0;j<n;j++){
            if(((i>>j)&1)==1){
                a+=s[j];
                c+=s[n*2-1-j];
            }else{
                b+=s[j];
                d+=s[n*2-1-j];
            }
        }
        p[P(a, b)]++;
        q[P(c, d)]++;
    }
    for(auto x=p.begin();x!=p.end();x++){
        m+=(x->second)*q[(x->first)];
    }
    cout<<m<<endl;
}
