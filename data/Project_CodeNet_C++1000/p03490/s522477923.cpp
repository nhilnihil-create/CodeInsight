
#include <bits/stdc++.h>

#define ll int64_t
using namespace std;
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){
    IOS
    string s;
    cin>>s;
    ll x,y;
    cin>>x>>y;
    map<ll,ll> xx;
    map<ll,ll> yy;
    xx[0]=1;
    ll cnt=0;
    ll to_inc=0;
    for(auto pp:s){
        if(pp=='T') {
            if(cnt%2==0){
                set<ll> gett;
                for(auto kk:xx){
                    if(kk.second>0) {
                        gett.insert(kk.first+to_inc);
                        if(cnt>0) gett.insert(kk.first-to_inc);}
                }
                xx.clear();
                for(auto pp:gett){
                    xx[pp]++;
                }
                
            }
            cnt++;
            to_inc=0;
        }
        else if(cnt%2==0) to_inc++;
       // dbg2(pp,to_inc);
        //for(auto kk:xx){
          //      //dbg(kk.first);
        // }
        
    }
    if(to_inc&&cnt%2==0){
        set<ll> gett;
                for(auto kk:xx){
                    if(kk.second>0) {
                        gett.insert(kk.first+to_inc);
                        if(cnt>0) gett.insert(kk.first-to_inc);}
                }
                xx.clear();
                for(auto pp:gett){
                    xx[pp]++;
                }
    }
    yy[0]=1;
    to_inc=0;
    cnt=0;
    for(auto pp:s){
        if(pp=='T') {
            if(cnt%1==0){
                set<ll> gett;
                for(auto kk:yy){
                    if(kk.second>0) {gett.insert(kk.first+to_inc); gett.insert(kk.first-to_inc);}
                }
                yy.clear();
                for(auto pp:gett){
                    yy[pp]++;
                }
                
            }
            cnt++;
            to_inc=0;
        }
        else if(cnt%2==1) to_inc++;
        
    }


     if(to_inc&&cnt%2==1){
        set<ll> gett;
                for(auto kk:yy){
                    if(kk.second>0) {
                        gett.insert(kk.first+to_inc);
                        if(cnt>0) gett.insert(kk.first-to_inc);}
                }
                yy.clear();
                for(auto pp:gett){
                    yy[pp]++;
                }
    }
   

    if(xx[x]>0&&yy[y]>0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}