#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    long long sm=0;
    for(int i=0; i<n; i++){
        cin >> h[i];
        sm += h[i];
    }
    sort(h.begin(),h.end());
    long long mn=sm;
    for(int i=0; i<n-k+1;i++){
        mn = min(mn,(long long) h[i+k-1]-h[i]);
    }
    cout << mn << endl;


}


