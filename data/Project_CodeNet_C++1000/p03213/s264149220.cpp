#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MAXN = 301;

int main(){
    int N; cin >> N;
    vector<int> V(101);
    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 2; i <= N; i++) {
        int p = i;
        for(int j = 2; j*j<=i; j++){
            while(p%j==0){
                V[j]++;
                p/=j;
            }
        }
        if(p != 1) V[p]++;
    }
    ll ans = 0;
    map<int, int> M;
    
    for(int i = 2; i <= N; i++){
        if(V[i] >= 4){

            for(int j = i+1; j <= N; j++){
                if(j!=i && V[j] >= 4){

                    for(int k = 2; k <= N; k++){
                        if(k!=i && k!= j && V[k]>= 2) {
                            //cout << i << " " << j << " " << k << endl;
                            ans++;
                        }
                    }
                }
                
            }
        }
    }


    //cout << ans << endl;
    int tmp = 0;
    for(int i = 2; i <=N; i++){
        if(V[i] >= 14){
            for(int j = 2; j <= N; j++){
                if(V[j] >= 4 && i!=j){
                    tmp++;
                }
            }
        }
        
    }
    ans+= tmp;
    //cout << tmp << endl;
    tmp=0;
    for(int i = 2; i <=N; i++){
        if(V[i] >= 24){
            for(int j = 2; j <= N; j++){
                if(V[j] >= 2 && i!= j){
                    tmp++;
                }
            }
        }
        
    }
    ans+= tmp;
    //cout << tmp << endl;
    tmp=0;
    
    for(int i = 2; i <= N; i++) if(V[i] >= 74) ans++;
    cout << ans << endl;

}