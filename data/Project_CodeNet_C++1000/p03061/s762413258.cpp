#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    if(x%y==0) return y;
    else{
        return gcd(y, x%y);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A.at(i);
    }
    vector<int> L(n);
    vector<int> R(n);
    L.at(0)=A.at(0);
    R.at(n-1)=A.at(n-1);
    for(int i=0; i<n-1;i++){
        L.at(i+1) = gcd(max(L.at(i),A.at(i+1)), min(L.at(i),A.at(i+1)));
    }
    
    for(int i=n-1; i>=1; i--){
        R.at(i-1) = gcd(max(R.at(i),A.at(i-1)), min(R.at(i),A.at(i-1)));
    }
    int ans=max(R.at(1), L.at(n-2));
    for(int i=1; i<n-1; i++){
        int calc;
        calc=gcd(L.at(i-1),R.at(i+1));
        ans = max(ans, calc);
    }
    cout << ans << endl;
}