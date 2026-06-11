#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    long long a[k];
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    long long mini,maxi;
    mini = 2;
    maxi = 2;
    for(int i=k-1; i>=0; i--){
        if(mini%a[i]!=0){
            mini = (mini/a[i]+1)*a[i];
        }
        if(maxi%a[i]!=0){
            maxi = (maxi/a[i])*a[i];
        }
        maxi += a[i]-1;
    }
    if(mini > maxi) cout << -1 << endl;
    else cout << mini << " " << maxi << endl;
    return 0;
}
