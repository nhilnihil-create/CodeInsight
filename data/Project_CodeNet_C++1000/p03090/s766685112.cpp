#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<ll> a,b;
    if(N%2==0){
        vector<Pll> v;
        rep(i,N/2){
            v.push_back(Pll(i+1,N-i));
        }
        ll n;
        if(N != 4){
            n = 4*v.size();
        }else{
            n = 4*(v.size()-1);
        }
        cout << n << endl;
        rep(i,N/2 - 1){
            cout << v[i%(N/2)].first << " " << v[(i+1)%(N/2)].first << endl;
            cout << v[i%(N/2)].first << " " << v[(i+1)%(N/2)].second << endl;
            cout << v[i%(N/2)].second << " " << v[(i+1)%(N/2)].first << endl;
            cout << v[i%(N/2)].second << " " << v[(i+1)%(N/2)].second << endl;
        }
        if(N != 4){
            cout << v[0].first << " " << v[N/2-1].first << endl;
            cout << v[0].first << " " << v[N/2-1].second << endl;
            cout << v[0].second << " " << v[N/2-1].first << endl;
            cout << v[0].second << " " << v[N/2-1].second << endl;
        }
        /*
        rep(i,N/2){
            if(i%2==0){
                a.push_back(i);
                a.push_back(N-1-i);
            }else{
                b.push_back(i);
                b.push_back(N-1-i);
            }
        }
        cout << a.size()*b.size() << endl;
        rep(i,a.size()){
            rep(j,b.size()){
                cout << a[i]+1 << " " << b[j]+1 << endl;
            }
        }*/
        return 0;
    }else{
        N--;
        vector<Pll> v;
        rep(i,N/2){
            v.push_back(Pll(i+1,N-i));
        }
        ll n;
        if(N != 2){
            n = 4*(v.size());
        }else{
            n = 2;
        }
        cout << n << endl;
        rep(i,N/2 - 1){
            cout << v[i%(N/2)].first << " " << v[(i+1)%(N/2)].first << endl;
            cout << v[i%(N/2)].first << " " << v[(i+1)%(N/2)].second << endl;
            cout << v[i%(N/2)].second << " " << v[(i+1)%(N/2)].first << endl;
            cout << v[i%(N/2)].second << " " << v[(i+1)%(N/2)].second << endl;
        }
            cout << N+1 << " " << v[N/2-1].first << endl;
            cout << N+1 << " " << v[N/2-1].second << endl;
        if(0 != N/2-1){
            cout << N+1 << " " << v[0].first << endl;
            cout << N+1 << " " << v[0].second << endl;
        }
        /*
        rep(i,a.size()){
            cout << N+1 << " " << a[i]+1 << endl;
        }
        rep(i,b.size()){
            cout << N+1 << " " << b[i]+1 << endl;
        }*/
        return 0;
    }
}