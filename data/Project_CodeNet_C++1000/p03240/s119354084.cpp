#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX

typedef pair<int, int> P;
int main(){
    long long n;
    cin>>n;
    vector<long long> x(n);
    vector<long long> y(n);
    vector<long long> h(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>h[i];
    }
    bool flag=1;
    rep(i,101){
        rep(j,101){
                long long p=-1;
                rep(q,n){
                    long long mx=h[q]+abs(x[q]-j)+abs(y[q]-i);
                    if(h[q]!=0 && p==-1){
                        p=mx;
                        break;
                        
                    }
                }
                flag=1;
                rep(q,n){ 
                    long long hh=max(p-abs(x[q]-j)-abs(y[q]-i),0LL);
                    if (hh!=h[q]){
                        flag=0;
                        break;
                    }
                }
                if (flag){
                    cout<<j<<" "<<i<<" "<<p<<endl;
                }
                
               
            }
           
        }
        
    }