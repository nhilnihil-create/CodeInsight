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
using namespace std;


int main(){
    long long n;
    cin >> n;
    vector<pair<long long, long long> > a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i].second >> a[i].first;
    for(int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    long long ans = 0;
    cout << endl;
    for(int i = 0; i < n; ++i){
        long long s = b[i].first, f = b[i].second;
        int in = -1;
        for(int j = 0; j < n; ++j){
            if(a[j].first < f && a[j].second < s){
                in = max(in, j);
            }
        }
        if(in != -1){
            ans++;
            a[in].first = a[in].second = 1e9;
        }
    }
    cout << ans;
}