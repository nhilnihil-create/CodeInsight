#include <bits/stdc++.h>
using namespace std;

using ll = long long int;


int main(){
    ll n, q;
    string s;
    cin >> n >> s >> q;
    for(;q>0;q--){
        int k;
        cin >> k;
        ll d=0,m=0,dm=0,dmc=0;
        for(int i=0;i<k;i++){
            if(s[i]=='D'){
                d++;
            }
            if(s[i]=='M'){
                dm += d;
                m++;
            }
            if(s[i]=='C'){
                dmc += dm;
            }
        }
        for(int i=k;i<n;i++){
            if(s[i-k]=='D'){
                dm -= m;
                d--;
            }
            if(s[i-k]=='M'){
                m--;
            }
            if(s[i]=='D'){
                d++;
            }
            if(s[i]=='M'){
                dm += d;
                m++;
            }
            if(s[i]=='C'){
                dmc += dm;
            }
        }
        cout << dmc << endl;
    }
    return 0;
}
