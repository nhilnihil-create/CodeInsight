#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define sort(s) sort(s.begin(),s.end())
#define reverse(s) reverse(s.begin(),s.end())
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

int main(){
    int n,m,c; cin >> n >> m >> c;
    int B[m];
    rep(i,m){ cin >> B[i]; }
    int A[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }

    bool flag[n];
    rep(i,n){
        flag[i] = false;
    }

    for(int i=0;i<n;i++){
        int ans(0);
        for(int j=0;j<m;j++){
            ans = ans + A[i][j]*B[j]; 
        }
        ans += c;
        if(ans > 0){
            flag[i] = true;
        }
        
    }

    
    int count(0);
    rep(i,n){
        if(flag[i]==true){
            count++;
        }
        
    }
    cout << count << endl;


    //int l(0);
    //rep(i,n){
    //    if(flag[i]==false)l++;
    //}
    //if(l==n) cout << false << endl;

return 0;

}