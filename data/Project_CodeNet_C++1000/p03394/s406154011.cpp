#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    if(n == 3){
        cout << "2 5 63" << endl;
    }else{
        vector<ll> ans = {2,3,4,9};
        n -= 4;
        for(int k = 15; k <= 30000; k += 12){
            if(n > 1 && k+6 <= 30000){
                ans.push_back(k);
                ans.push_back(k+6);
                n -= 2;
            }else{
                break;
            }
        }
        for(int k = 8; k <= 30000; k += 6){
            if(n > 1 && k+2 <= 30000){
                ans.push_back(k);
                ans.push_back(k+2);
                n -= 2;
            }else{
                break;
            }
        }
        for(int k = 6; k <= 30000 && n > 0; k += 6){
            ans.push_back(k);
            n--;
        }
        for(int i = 0; i < ans.size(); i++){
            if(i > 0){
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }
    
    return 0;
}