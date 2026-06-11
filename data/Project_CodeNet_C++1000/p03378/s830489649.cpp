#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector <int> v(m);
    int left=0,right=0;
    for(int i = 0; i < m; i++){
        cin >> v[i];
        if(v[i]<x){
            left++;
        }else{
            right++;
        }
    }
    int ans = min(left,right);
    cout << ans << endl;
    return 0;
}