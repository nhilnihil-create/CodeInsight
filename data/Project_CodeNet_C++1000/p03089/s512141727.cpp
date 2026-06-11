#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;


int main()
{
    int n;
    cin >> n;
    vector<int> b;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        b.push_back(k);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int s = b.size();
        bool change = false;
        for(int j = s-1; j >= 0; j--){
            if(b[j] == j+1){
                change = true;
                ans.push_back(b[j]);
                b.erase(b.begin()+j);
                break;
            }
        }
        if(!change){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}