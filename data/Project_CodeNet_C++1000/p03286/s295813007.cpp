#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    string ans;
    while(1){
        if(n%2==0){
            n = -n/2;
            ans.push_back('0');
        }
        else{
            n = n-1;
            n = -n/2;
            ans.push_back('1');
        }
        if(n==0) break;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}