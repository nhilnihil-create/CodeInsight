#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, K, ans=0, tmp=0;
vector<ll> A, B;
map<ll,ll> M;

signed main(){
    cin >> N >> K;
    A.push_back(0);
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        tmp = A.back();
        a += tmp;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<=N;j++) {
            ll num = A[j]-A[i];
            B.push_back(num);
            int k=0;
            while(num>=1) {
                M[k]+=num%2;
                num /= 2;
                k++;
            }
        }
    }
    ll id=0;
    map<ll,ll>::iterator itr=M.end();
    while(itr!=M.begin()) {
        itr--;
        pair<ll,ll> p = *itr;
        if(p.second>=K) {
            ans += pow(2,p.first);
            for(int i=0;i<B.size();i++) {
                ll nump = B[i]/pow(2,p.first);
                if(nump%2==0) {
                    B[i] = 0;
                }
            }
            break;
        }
    }
    while(itr!=M.begin()) {
        itr--;
        pair<ll,ll> p = *itr;
        ll ct=0;
        for(int i=0;i<B.size();i++) {
            ll nump = B[i]/pow(2,p.first);
            if(nump%2==1) {
                ct++;
            }
        }
        if(ct>=K) {
            ans += pow(2,p.first);
            for(int i=0;i<B.size();i++) {
                ll nump = B[i]/pow(2,p.first);
                if(nump%2==0) {
                    B[i] = 0;
                }
            }
        }
    }    
    cout << ans << endl;
    return 0;
}