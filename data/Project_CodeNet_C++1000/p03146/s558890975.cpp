#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
bool isacgt(char c){
    return (
        c=='A' || c=='C' || c=='G' || c=='T'
    );
}

int func(int n){
    int ans;
    if(n%2==0){
        ans = n/2;
    }else{
        ans = 3*n+1; 
    }
    
    return ans;
}

int main() {

    int s;
    cin >> s;

    int m = 1000000; //10e6
    vector<int> a(m);

    int ans = 0;
    bool forfinish = false;
    rep(i,m){
        if(i==0){
            a[i] = s;
        }else{
            a[i] = func(a[i-1]);
        }
        rep(j,i){
            if(a[j]==a[i]){
                ans = i+1;
                forfinish = true;
                break;
            }
        }
        if(forfinish){
            break;
        }
    }

    cout << ans << endl;

    return 0;

}