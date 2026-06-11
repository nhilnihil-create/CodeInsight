#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    int n; cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int ma=0, mi=0;
    rep(i,n){
        if(p[i]>p[ma]) ma=i;
        if(p[i]<p[mi]) mi=i;
    }
    if(p[mi]>=0){
        cout<<2*n<<endl;
        rep(ii,2){
            cout<<ma+1<<" "<<1<<endl;
        }
        rep(i,n-1){
            rep(jj,2){
                cout<<1+i<<" "<<2+i<<endl;
            }
        }
    }else{
        if(p[ma]<=0){
            cout<<2*n<<endl;
            rep(ii,2){
                cout<<mi+1<<" "<<n<<endl;
            }
            rep(i,n-1){
                rep(jj,2){
                    cout<<n-i<<" "<<n-1-i<<endl;
                }
            }
        }else{
            if(p[ma]>=abs(p[mi])){
                cout<<2*n<<endl;
                rep(ii,2){
                    cout<<ma+1<<" "<<1<<endl;
                }
                rep(i,n-1){
                    rep(jj,2){
                        cout<<1+i<<" "<<2+i<<endl;
                    }
                }
            }else{
                cout<<2*n<<endl;
                rep(ii,2){
                    cout<<mi+1<<" "<<n<<endl;
                }
                rep(i,n-1){
                    rep(jj,2){
                        cout<<n-i<<" "<<n-1-i<<endl;
                    }
                }
            }
        }
    }
}