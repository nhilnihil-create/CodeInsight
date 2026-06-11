#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll nnn;
    nnn=n;
    queue <ll> a35,a37,a57,b,aa,bb,kara;
    int k=0;
    while(n!=0){
        n/=10;
        k+=1;
    }
    ll ans=0;
    ll e=0;
    int l=0,l2=0;
    if(k<=2){
        cout << 0 << endl;
    }
    else{
        a35.push(35);
        a37.push(37);
        a35.push(53);
        a57.push(57);
        a37.push(73);
        a57.push(75);
        rep(i,k-2){
            bb=kara;
            aa=kara;
            l=a35.size();
            l2=b.size();
            ans+=l2;
            ll x;
            rep(j,l2){
                x=b.front();
                b.pop();
                bb.push(x*10+3);
                bb.push(x*10+5);
                bb.push(x*10+7);
            }
            rep(j,l){
                x=a35.front();
                a35.pop();
                bb.push(x*10+7);
                aa.push(x*10+3);
                aa.push(x*10+5);
            }
                e=0;
                rep(jj,i+2){
                    e+=pow(10,jj)*3;
                }
                aa.push(e*10+5);
                e=0;
                rep(jj,i+2){
                    e+=pow(10,jj)*5;
                }
                aa.push(e*10+3);
            
            a35=aa;
            aa=kara;
            rep(j,l){
                x=a37.front();
                a37.pop();
                bb.push(x*10+5);
                aa.push(x*10+3);
                aa.push(x*10+7);
                
                
            }
            e=0;
            rep(jj,i+2){
                    e+=pow(10,jj)*3;
                }
                aa.push(e*10+7);
                e=0;
                rep(jj,i+2){
                    e+=pow(10,jj)*7;
                }
                aa.push(e*10+3);
            a37=aa;
            aa=kara;
            rep(j,l){
                x=a57.front();
                a57.pop();
                bb.push(x*10+3);
                aa.push(x*10+5);
                aa.push(x*10+7);
            }
                e=0;
                rep(jj,i+2){
                    e+=pow(10,jj)*5;
                }
                aa.push(e*10+7);
                e=0;
                rep(jj,i+2){
                    e+=pow(10,jj)*7;
                }
                aa.push(e*10+5);
            
            a57=aa;
            aa=kara;
            b=bb;
        }
    
    //cout << ans << endl;

    ll nn=b.size();
    ll p;
    rep(i,nn){
        p=b.front();
        b.pop();
        
        if(p<=nnn){
            ++ans;
            //cout << p << endl;
        }
    }

    cout << ans << endl;

    
    }
    return 0;
}