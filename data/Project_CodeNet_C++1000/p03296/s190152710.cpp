#include <bits/stdc++.h>
using namespace std;
 
#define rep for(int i = 0;i<n;i++)
const int MOD = 1000000007;
 
int main(){
    int n; cin >> n;
    int ans = 0;
    int a[n];rep{
        cin >> a[i];
    }
    int i = 1;
    while(i<n){
        if(a[i-1]==a[i]){
            ans+=1; i+=2;
        }else{
            i++;
        }
    }
    cout << ans << endl;
}