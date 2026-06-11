#include <iostream>
using namespace std;
typedef long long ll;
int n;
string s;
ll f(int k){
    ll r=0,d=0,m=0,dm=0;
    for(int i=0;i<n;i++){
        if(i-k>=0){
            if(s[i-k]=='D'){
                d--;
                dm-=m;
            }else if(s[i-k]=='M'){
                m--;
            }
        }
        if(s[i]=='D'){
            d++;
        }else if(s[i]=='M'){
            m++;
            dm+=d;
        }else if(s[i]=='C'){
            r+=dm;
        }


    }
    return r;
}
int main(void){
    int q;
    cin>>n>>s>>q;
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        ll ans=f(k);
        cout << ans << endl;
    }
}
