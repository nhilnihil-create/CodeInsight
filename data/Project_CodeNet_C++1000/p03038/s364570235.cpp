#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
int a[N], n, m;
vector<pair<int,int>> v;
int BS(int startLow, int k){
    int low = startLow, high = n - 1, mid, ans = -1;
    while(low <= high){
        mid = (low + high)/2;
        if(a[mid] < k){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int main(){
    Hello
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0, b, c; i < m; i++){
        cin >> b >> c;
        v.push_back({c, b});
    }
    sort(a, a + n);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
//    for(int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//    for(int i = 0; i < v.size(); i++)
//        cout << v[i].second << " " << v[i].first << endl;
//    cout << endl;
    int cs[m + 5] = {}, startLow = 0;
    for(int i = 0; i < v.size(); i++){
        int ret = BS(startLow, v[i].first);
       // cout << i << " startlow: " << startLow << " k: " << v[i].first << " size: " << v[i].second << " ret: " << ret << endl;
        if(ret != -1){
            cs[i] = startLow + min(ret - startLow, v[i].second - 1);
            startLow = cs[i] + 1;
     //       cout << "last idx: " << cs[i] << endl;
        }
        else cs[i] = 1e9;
    }
    ll sum = 0, lst = 0;
    for(int i = 0; i < m; i++){
        if(cs[i] != 1e9){
            for(int j = lst; j <= cs[i]; j++)
                a[j] = v[i].first;
            lst = cs[i] + 1;
        }
    }
    for(int i = 0; i < n; i++){
        //cout << a[i] << " ";
        sum += a[i];
    }
    cout << sum;
    return 0;
}
