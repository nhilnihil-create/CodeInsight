#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
int main()
{
    ll N;
    cin >> N;
    vector<ll> D(N);
    map<ll, ll> A;
    rep(i,N){
        cin >> D.at(i);
        A[D.at(i)]++;
    }
    ll M;
    cin >> M;
    vector<ll> T(M);
    rep(i,M){
        cin >> T.at(i);
        if(A.count(T.at(i))){
            A[T.at(i)]--;
            if(A[T.at(i)]<0){
                cout << "NO" << endl;
                return 0;
            }
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}