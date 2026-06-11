#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll nw=0, nb=0;
    rep(i,N){
        if(S[i] == '#'){
            nb++;
        }else{
            nw++;
        }
    }
    ll m = 1e10;
    m = min(m,nw);
    nb = 0;
    rep(i,N){
        if(S[i] == '.'){
            nw--;
        }else{
            //nw++;
            nb++;
        }
        m = min(m, nw+nb);
    }
    cout << m << endl;
    /*char now = '.';//.#.#.
    int cnt = 0;
    vector<ll> v;
    rep(i,N){
        if(now != S[i]){
            v.push_back(cnt);
            cnt = 1;
            if(now == '.'){
                now = '#';
            }else{
                now = '.';
            }
        }else{
            cnt++;
        }
    }
    if(cnt != 0) v.push_back(cnt);
    if(v.size() % 2 == 0) v.push_back(0);
    rep(i,v.size()){
        if(v[i] == 0){
            v.erase(i);
        }
    }
    vector<ll> s1(v.size() + 2),s2(v.size()+2);
    //cout << endl;
    for(int i = 0;i<v.size();i+=2){
        s1[i+2] = v[i] + s1[i];
        //cout << s1[i+2] << endl;
    }
    if(v.size % 2 == 1){
    for(int i = int(v.size()-2);i>0;i-=2){
        s2[i-1] = v[i] + s2[i+1];
    }
    }
    /*rep(i,v.size()+2){
        cout << s1[i] << " " << s2[i] <<endl;
    }
    ll m = 1e10;
    for(int i = 0;i<int(v.size()+2);i+=2){
        m = min(s1[i]+s2[i],m);
    }*/
    //cout << m << endl;
}