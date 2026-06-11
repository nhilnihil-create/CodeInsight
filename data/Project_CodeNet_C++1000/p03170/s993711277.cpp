
/**
 *    author        : Saurav Paul 
 *    created       : August 14, 2020 9:28 PM
 *    Problem Name  : K - Stones
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/dp/tasks/dp_k
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

void solve(){
    int N , K ;
    cin >> N >> K ;

    bool dp[K+1] = {} ;
    vector<int> v(N) ;
    for(auto &x : v){
        cin >> x;
    }

    for(int stones = 0 ; stones <= K ; stones ++){
        for(auto x : v){
            if(stones >= x){
                if(!dp[stones-x]) dp[stones] = true ;
            }
        }
    }

    cout << (dp[K]?"First":"Second") << endl ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
