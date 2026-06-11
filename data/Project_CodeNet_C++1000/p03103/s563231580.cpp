#include <bits/stdc++.h>
 using namespace std;
int main(){ 
    long long  n,m; 
    cin >> n >> m; 
    vector<pair<long long,long long>> v;
     for(int i=0;i<n;i++){ 
        long long a,b; 
        cin >> a >> b; v.push_back(make_pair(a,b));
         } 
    sort(v.begin(),v.end());
     long long  purchaseNum = m;
     long long sum = 0; 
    for(int i=0;i<n;i++){ 
        if(purchaseNum>=v[i].second)
         sum += v[i].first*v[i].second; 
        else sum += v[i].first*purchaseNum; purchaseNum -= v[i].second; if(purchaseNum<=0)
         break; } 
    cout << sum << endl;
    return 0; } 
