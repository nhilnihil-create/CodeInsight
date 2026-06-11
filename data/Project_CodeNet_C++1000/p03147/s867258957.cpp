#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> h(100);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int ans = 0;
    for(int l=0; l<n; l++){
        while(h[l]>0){
            int r=0;
            for(r=l+1; r<n; r++){
                if(h[r]==0)
                    break;
            }
            for(int i=l; i<r; i++){
                h[i]--;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}