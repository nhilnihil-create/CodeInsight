#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp.at(0)=0;
    for(int i=1; i<n+1; i++){
        dp.at(i) = dp.at(i-1)+1;
        int k=6;
        while(k<=i){
            dp.at(i) = min(dp.at(i),dp.at(i-k)+1);
            k*=6;
        }
        k=9;
        while(k<=i){
            dp.at(i) = min(dp.at(i), dp.at(i-k)+1);
            k*=9;
        }
    }
    cout << dp.at(n) << endl;
}