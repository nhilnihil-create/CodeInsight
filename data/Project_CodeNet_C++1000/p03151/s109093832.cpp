#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll lack = 0;
    int lacknum = 0;
    for(int i = 0; i < n; i++){
        if(b[i]-a[i] > 0){
            lack += b[i]-a[i];
            lacknum++;
        }
    }

    vector<int> surplus;
    for(int i = 0; i < n; i++){
        if(a[i]-b[i] > 0) surplus.push_back(a[i]-b[i]);
    }
    sort(surplus.begin(), surplus.end(), greater<int>());

    if(lack == 0){
        cout << 0 << endl;
    }else{
        ll sum = 0;
        int ans = 0;
        for(; ans < surplus.size();){
            sum += surplus[ans++];
            if(sum >= lack) break;
        }

        if(sum >= lack) cout << ans+lacknum << endl;
        else cout << -1 << endl;
    }
    return 0;
}