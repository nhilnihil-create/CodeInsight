#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> left,right;
    bool hav=false;
    int memo;
    if(s[0]=='0') left.push_back(1);
    rep(i,n){
        if(s[i]=='1' && hav==false){
            memo=i;
            hav=true;
        } 
        if(s[i]=='0' && hav==true){
            left.push_back(memo+1);
            hav=false;
        }
    }
    hav=false;
    if(s[n-1]=='0') right.push_back(n);
    for(int i=n-1; i>=0; i--){
        if(s[i]=='1' && hav==false){
            memo=i;
            hav=true;
        } 
        if(s[i]=='0' && hav==true){
            right.push_back(memo+1);
            hav=false;
        }
    }
    reverse(all(right));
    //rep(i,right.size()) cout << left[i] << ' ' << right[i] << endl;
    if(left.size()<=k){
        cout << n << endl;
        return 0;
    }
    int ans=0;
    rep(i,right.size()-k+1){
        ans=max(ans,right[i+k-1]-left[i]+1);
    }
    cout << ans << endl;
return 0;
}