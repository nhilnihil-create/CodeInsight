#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; ++i){cin >> h[i];}
    int res = 0;
    while(1){ 
        int l = -1, r = -1;
        for(int i=0; i<n; ++i){
            if(h[i]!=0){l = i; break;}
        } //cout << l << ",";
        if(l==-1){break;} 
        for(int i=l; i<n; ++i){ 
            if(i==n-1){r = n-1;} //cout << "i=" << i << ", " << l << "," << r << endl;
            if(h[i]==0){r = i-1;break;}
        } //cout << r << endl;
        //for(int i=0; i<n; ++i){cout << h[i] << ",";} cout << res << endl;
        int mi =  10000000;
        for(int i=l; i<r+1; ++i){
            mi = min(mi, h[i]);
        }
        for(int i=l; i<r+1; ++i){h[i] -= mi;}
        res += mi;
    }
    cout << res << endl;
    return 0;
}