#include<bits/stdc++.h>
using namespace std;

int main(){
    long n; cin >> n;
    long cnt = 0;
    vector<long> I(n);
    vector<long> J(n);
    vector<long> K(n);
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            if(i == 0)cin >> I[j];
            else if(i == 1)cin >> J[j];
            else cin >> K[j];
        }
    }
    sort(I.begin(),I.end());
    sort(K.begin(),K.end());
    for(int i=0;i<n;i++){
        long a = lower_bound(I.begin(),I.end(),J[i]) - I.begin();
        long b = K.end()-upper_bound(K.begin(),K.end(),J[i]);
        cnt += a*b;
    }
    cout << cnt << endl;
}