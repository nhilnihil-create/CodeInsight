#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long int


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll n;
    cin >> n;
    ll N = 1 << n;
    vector<pair<ll, ll> > d(N);
    for(int i = 0; i < N; ++i) cin >> d[i].first;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < N; ++j){
            if(j&(1<<i)){
                int s = j^(1<<i);
                if(d[j].first < d[s].first){
                    d[j].second = max(d[j].first, d[s].second);
                    d[j].first = d[s].first;
                }
                else d[j].second = max(d[j].second, d[s].first);
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i < N; ++i){
        ans = max(ans, d[i].first + d[i].second);
        cout << ans << endl;
    }
}