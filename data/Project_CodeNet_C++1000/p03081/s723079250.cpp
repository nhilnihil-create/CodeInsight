#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
#define pow_10_5 100000
#define pow_10_9 1000000000

// ---
const int Qlim = 2*pow_10_5;
int N, Q;
string s;
char t[Qlim], d[Qlim];

bool leftOut(int pos){
    rep(i,Q){
        if(s[pos]==t[i]){
            if(d[i]=='L'){
                pos--;
                if(pos<0) return true;
            } 
            else{
                pos++;
                if(pos>N-1) return false;
            }
        }
    }
    return false;
}

bool rightOut(int pos){
    rep(i,Q){
        if(s[pos]==t[i]){
            if(d[i]=='L'){
                pos--;
                if(pos<0) return false;
            } 
            else{
                pos++;
                if(pos>N-1) return true;
            }
        }
    }
    return false;
}

int Ans(){
    int ans=N;
    
    // [l,r)
    if(leftOut(0)){
        int l=0,r=N;
        while(l+1!=r){
            int m = (l+r)/2;
            if(leftOut(m)){
                l = m;
            }
            else{
                r = m;
            }
        }
        ans -= l+1;
    }

    // (l,r]
    if(rightOut(N-1)){
        int l=-1,r=N-1;
        while(l!=r-1){
            int m = (l+r)/2;
            if(rightOut(m)){
                r = m;
            }
            else{
                l = m;
            }
        }
        ans -= N-r;
    }
    return ans;
}

int main() {
    cin >> N >> Q;
    cin >> s;
    rep(i,Q) {cin >> t[i] >> d[i];}
    int ans = Ans();
    cout << ans << endl;
    return 0;
}