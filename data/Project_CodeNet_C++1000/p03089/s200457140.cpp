#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    vi b(n);
    vi ans;
    rep(i,n) cin >> b[i];
    for(int i=0;i<n;i++){
        for(int j=b.size()-1;j>=0;j--){
            if(j+1==b[j]){
                ans.push_back(b[j]);
                b.erase(b.begin()+j);
                break;
            }
        }
    }
    if(b.size()) cout << "-1" << endl;
    else{
        reverse(ans.begin(),ans.end());
        for(int x: ans){
            cout << x << endl;
        }
    }  
}