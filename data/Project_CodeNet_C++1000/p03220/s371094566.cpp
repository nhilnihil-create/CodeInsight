#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,a;
    cin >> n >> t >> a;
    vector <int> h(n);
    vector <long double> palaceT(n);
    long double diff;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        palaceT[i] = (long double)t - (long double)0.006*(long double)h[i];
        if(i == 0){
            diff = abs((long double)a-palaceT[i]);
            ans = i + 1;
        }else{
            if(diff > abs((long double)a-palaceT[i])){
                diff = abs((long double)a-palaceT[i]);
                ans = i+1;
            }
        }
        //cout << abs((long double)a-palaceT[i]) << " ";
        //cout << diff << " ";
    }
    //cout << endl;
    #if 0
    for(int i = 0; i < n; i++){
        cout << palaceT[i] << " ";
    }
    cout << endl;
    #endif
    cout << ans << endl;
    return 0;
}