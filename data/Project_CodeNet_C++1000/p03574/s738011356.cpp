#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
    ll H,W;
    cin>>H>>W;
string S;
for(ll i=0;i<W+2;i++) {
    S+='.';
}
vector<string> vec(H+2);
vec[0]=S;
vec.back()=S;
for(ll i=0;i<H;i++) {
    string A;
    cin>>A;
    A='.'+A+'.';
    vec[i+1]=A;
}
vector<vector<char>> T(H,vector<char>(W));

for(ll i=1;i<=H;i++) {
    for(ll j=1;j<=W;j++) {
        if(vec[i][j]=='.') {
            ll count=0;
            if(vec[i][j+1]=='#') {
                count++;
            }
            if(vec[i][j-1]=='#') {
                count++;
            }
            if(vec[i-1][j]=='#') {
                count++;
            }
            if(vec[i+1][j]=='#') {
                count++;
            }
            if(vec[i+1][j+1]=='#') {
                count++;
            }
            if(vec[i+1][j-1]=='#') {
                count++;
            }
            if(vec[i-1][j+1]=='#') {
                count++;
            }if(vec[i-1][j-1]=='#') {
                count++;
            }

T[i-1][j-1]='0'+count;
        }

        else {
            T[i-1][j-1]='#';
        }
    }
        }

        for(ll i=0;i<H;i++) {
            for(ll j=0;j<W;j++) {
                cout<<T[i][j];
            }
            cout<<endl;
        }
            
}

        
