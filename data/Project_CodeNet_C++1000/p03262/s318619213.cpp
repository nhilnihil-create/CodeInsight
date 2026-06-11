#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    int x,y;
    x=max(a,b);
    y=min(a,b);
    if(x%y==0) return y;
    else return gcd(x%y, y);
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> dif(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        dif.at(i) = abs(x-k);
    }
    int ans=dif.at(0);
    for(int i=0; i<n; i++){
        ans = gcd(ans, dif.at(i));
    }
    cout << ans << endl;
}