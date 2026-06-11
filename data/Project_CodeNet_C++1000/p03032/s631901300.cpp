#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int n;
int k;
list<long long> L;
int main()
{
    long long v;
    
    cin >> n >> k;
    int t = min(n,k);
    long long ans = 0;
    
    for (int i = 0;i < n;i++){
        cin >> v;
        L.push_back(v);
    }
    for (int i = 0;i <= t;i++){
        for (int j = 0;j <= t-i;j++){
            vector<long long> w;
            w.resize(i+j);
            long long res = 0;
            if (i == 0 && j == 0){
                continue;
            }
            int ii = 0;
            for (auto it1 = L.begin();ii < i;it1++){
                w.push_back(*it1);
                res += *it1;
                ii++;
            }
            int jj = 0;
            for (auto it2 = L.end();jj < j;it2--){
                if (it2 == L.end()){
                    ;
                }
                else {
                    w.push_back(*it2);
                    res += *it2;
                    jj++;
                }
            }
            sort(w.begin(),w.end());
            int u = min(k-i-j,(int)w.size());
            int ori = 0;
            while (u > 0){
                if (w[ori] < 0){
                    res += abs(w[ori]);
                }
                else {
                    goto EXIT;
                }
                ori++;
                u--;
            }
            EXIT:
            ans = max(res,ans);
        }
    }
    cout << ans << endl;
}
