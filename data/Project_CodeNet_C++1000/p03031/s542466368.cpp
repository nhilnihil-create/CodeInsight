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

int main(){
    // 入力
    int n, m; cin >> n >> m;
    vector<vector<int>> s(m);
    for(int i=0; i<m; i++){
        int k; cin >> k;
        for(int j=0; j<k; j++){
            int ss; cin >> ss;
            ss--;
            s[i].push_back(ss);
        }
    }
    vector<int> p(m);
    for(int i=0; i<m; i++){
        cin >> p[i];
    }

    int ans = 0;
    // bit全探索　swichのonoff全通り
    for(int bit=0; bit < (1 << n); bit++){

        int ok = 1;

        for(int li=0; li<m; li++){
            int num_swi = 0;

            for(int i=0; i<s[li].size(); i++){
                if(bit & (1 << s[li][i])) num_swi++;
            }

            if(num_swi % 2 != p[li]){
                ok = 0;
                break;
            }

        }

        if(ok==1) ans++;

    }

    cout << ans;

}