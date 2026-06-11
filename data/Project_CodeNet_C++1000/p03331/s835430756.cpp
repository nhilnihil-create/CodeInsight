#include <bits/stdc++.h>
using namespace std;

int sum(int value){
    int ans=0;
    while(value!=0){
        ans+=value%10;
        value /= 10;
    }
    return ans;
}

int main(){
    int n;
    int ans=10000001;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x1 = sum(i);
        int x2 = sum(n-i);
        ans = min(ans,x1+x2);
    }
    cout << ans << endl;
    return 0;
}