#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin>> n;
    vector<int> a(100000);
    map<int, int> mp;
    int MAX=0;
    int MIN = 1000000000;
    for(int i=0; i<n; i++){
        cin >> a[i];
        MAX = max(MAX, a[i]);
        MIN = min(MIN, a[i]);
        if(!mp.count(a[i])){
            mp[a[i]]=1;
        }else{
            mp[a[i]]++;
        }
    }
    int ans = 0;

    for (auto p: mp) {
		int x = p.first;
		int n = p.second;
		if (n < x) ans += n;
		else ans += n - x;
	}
    cout << ans << endl;
    return 0;

}