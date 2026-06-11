#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    
    
    int N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    
    vector<ll> C;
    for (int i = 1; i <= N; i++) {
        ll s = 0;
        rep(j,i) s += a[j];
        int sb = 0,sf = i-1;
        
        C.push_back(s);
        for (int j = sf+1; j < N; j++) {
            s -= a[sb];
            sb++;
            s += a[j];
            
            C.push_back(s);
        }
        
    }
    
    sort(all(C));
    
    
    //rep(i,int(C.size())) cout << C[i] << " ";cout << endl;
    //cout << endl;
    
    
   
    
    
    ll t = 1;
    vector<ll> A;
    vector<vector<ll>> B;
    A.push_back(t);
    B.push_back({});
    for (int i = 1; i < 40; i++) {
        t = t*2;
        A.push_back(t);
        B.push_back({});
        if(t > C.back()) break;
    }
    
    for (int i = 0; i < int(C.size()); i++) {
        for (int k = 0; k < int(A.size()); k++) {
            if((A[k]&C[i]) == A[k]) B[k].push_back(C[i]);
        }
    }
    
    
    for (int k = int(A.size())-1; k >= 0; k--) {
        if(int(B[k].size()) >= K){
            
            ll ans = A[k];
            
            int nn = k;
            vector<ll> E;
            E = B[k];
            while (nn != -1) {
                //cout << " sss " << A[nn] << endl;
                //rep(i,int(E.size())) cout << E[i] << " ";cout << endl;
                
                int nnn = -1;
                vector<vector<ll>> D;
                D.resize(40);
                for (int i = 0; i < int(E.size()); i++) {
                    for (int j = 0; j < int(A.size()); j++) if((E[i]&A[j]) == A[j]) D[j].push_back(E[i]);
                }
                
                for (int i = nn-1; i >= 0; i--) {
                    if(int(D[i].size()) >= K){
                        nn = i;
                        nnn = 1;
                        break;
                    }
                }
                
                if(nnn == -1){ cout << ans << endl; break;}
                else ans += A[nn];
                E = D[nn];
                
            }
            
            
            
            
            break;
        }
    }
    
    
    
    return 0;
}

