#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    string ans="";
    ll n=s.length();
    ll i0=0,i1=n-1;
    ll num=0;
    while(i0<i1){
        if(s[i0]=='x'){
            if(s[i1]=='x'){
                i0++;
                i1--;
            }
            else{
                i0++;
                num++;
            }
        }
        else{
            if(s[i1]=='x'){
                i1--;
                num++;
            }
            else{
                if(s[i0]==s[i1]){
                    i0++;
                    i1--;
                }else{
                    cout << -1<<endl;
                    return 0;
                }
            }
        }
    }
    cout << num<<endl;
    return 0;
}

