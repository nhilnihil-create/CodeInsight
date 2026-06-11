#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    ll ans=S.size();
    for(ll i=0;i<S.size()-1;i++){
        if(S[i]!=S[i+1]){
            ans=min(ans,max(i+1,(ll)S.size()-i-1));
        }
    }
    cout << ans << endl;
}