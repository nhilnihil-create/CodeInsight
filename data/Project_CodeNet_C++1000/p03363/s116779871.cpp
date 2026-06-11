#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long sum[n];
    sum[0] = a[0];
    for(int i=1;i<n;i++)sum[i] = sum[i-1] + a[i];
    set<long>s;
    map<long,int>m;
    for(int i=0;i<n;i++){
        s.insert(sum[i]);
        m[sum[i]]++;
    }
    long ans = 0;
    for(long i:s){
        long tmp = m[i];
        ans += tmp * (tmp-1)/2;
    }
    ans += m[0];
    cout << ans << endl;
    
}