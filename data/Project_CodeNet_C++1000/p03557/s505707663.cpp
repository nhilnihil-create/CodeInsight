//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

int main (){
    int n; cin >> n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    // bを中心に考える
    ll int ans = 0;
    for(int i=0;i<n;i++){
        ll int num_a = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        ll int num_c = c.end() - upper_bound(c.begin(),c.end(),b[i]);
        ans += num_a * num_c;
    }
    cout << ans;
}