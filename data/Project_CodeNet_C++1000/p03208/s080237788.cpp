#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,k;
    cin >> n >> k;
    k--;
    vector <long> h(n);
    for(long i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    vector <long> diffK(n,-1);
    for(long i = 0; i < n; i++){
        //cout << h[i] << " ";
        if(i>=k){
            diffK[i] = h[i] - h[i-k];
        }
    }
    //cout << endl;
    sort(diffK.begin(),diffK.end());
    for(long i = 0; i < n; i++){
        if(diffK[i]!=-1){
            cout << diffK[i] << endl;
            return 0;
        }
    }
    return 0;
}