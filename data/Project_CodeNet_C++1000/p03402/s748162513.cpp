#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b;
char res[100][100];

int main(){
    cin >> a >> b;
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            if(i<50) res[i][j]='.';
            else res[i][j]='#';
        }
    }
    ll countb=0;
    for(ll i=0;i<50;i+=2){
        for(ll j=0;j<100;j+=2){
            if(countb==b-1) break;
            res[i][j]='#';
            countb++;
        }
        if(countb==b-1) break;
    }
    ll counta=0;
    for(ll i=99;i>=50;i-=2){
        for(ll j=0;j<100;j+=2){
            if(counta==a-1) break;
            res[i][j]='.';
            counta++;
        }
        if(counta==a-1) break;
    }
    cout << 100 << " " << 100 << endl;
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            cout << res[i][j];
        }
        cout << endl;
    }
}
