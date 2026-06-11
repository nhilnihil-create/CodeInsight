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
    int m; cin >> m;
    vector<int> x(m);
    for(int i=0; i<m; i++){
        cin >> x[i];
    }

    sort(x.begin(),x.end());
    
    vector<int> sa(m-1);
    for(int i=0; i<m-1; i++){
        sa[i] = x[i+1] - x[i];
    }

    sort(sa.begin(),sa.end());
    // reverse(sa.begin(),sa.end());

    int ans = 0;
    for(int i=0; i<m-n; i++){
        ans += sa[i];
    }

    cout << ans;
}