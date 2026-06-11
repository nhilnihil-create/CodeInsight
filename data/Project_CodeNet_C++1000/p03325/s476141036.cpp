#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
        int count = 0;
        while(true){
            if(a[i]%2==0){
                a[i] = a[i]/2; count++;
            }else
                break;
        }
        ans += count;
    }
    cout << ans << endl;
    return 0;
}