#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n, m;
cin >> n >> m;
vector<ll> a(n);
for(int i = 0; i< n; i++) cin >> a[i];
sort(a.begin(), a.end());
vector<pair<ll, int>> p(m);
for(int i = 0; i< m; i++){ 
cin >> p[i].second >> p[i].first;
}
sort(p.begin(), p.end());
reverse(p.begin(), p.end());
vector<ll> d;
for(int i = 0; i< m; i++){
   for(int j = 0; j < p[i].second;j++){
             d.push_back(p[i].first);
             if(d.size()> n) break;
         }
}
int k = d.size();
for(int i =0; i< min(k,n); i++)a[i]=max(a[i],d[i]);
ll sum = 0;
for(int i=0; i< n; i++) sum += a[i];

cout << sum <<endl;
return 0;
}
     