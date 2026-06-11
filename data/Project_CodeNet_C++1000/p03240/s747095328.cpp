#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            int now;
            set<int> st;
            for(int k=0; k<n; k++){
                if(h[k]==0) continue;
                now = h[k]+abs(i-x[k])+abs(j-y[k]);
                
                st.insert(now);
            }
            if(st.size()==1){
                int check = true;
                auto itr = st.begin();
                rep(k,n){
                    if(h[k]==0){
                        if(abs(i-x[k])+abs(j-y[k])-*itr < 0) 
                            check = false;
                    }
                }
                if(check)
                cout << i << " " << j << " " << *itr << endl;
            }
        }
    }
    return 0;
}