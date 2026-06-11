#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    vector<int> A(n+2,0);
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    vector<int> D(n+1,0);
    int sum = 0;
    for(int i=0;i<n+1;i++){
        D[i] = abs(A[i+1] - A[i]);
        sum += D[i];
    }
    /*
    for(auto x:D){
        cout << x << " ";
    }
    
    cout << endl;
    */
    //cout << sum << endl;
    for(int i=1;i<=n;i++){
        int ans = sum;
        //cout << "消された" << D[i-1] + D[i] << endl;
        ans -= (D[i-1] + D[i]);
        ans += abs(A[i+1]-A[i-1]);
        cout << ans << endl;
    }
}