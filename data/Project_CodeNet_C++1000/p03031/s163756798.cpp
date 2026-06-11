#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
#include <map>
using namespace std;
int main(void){
    int n, m; cin >> n >> m;
    vector< vector<int> > v(m);
    map<int, int> map;
    int i = 0;
    while (i < m) {
        int k;
        cin >> k;
        int j = 0;
        while (j < k) {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < m) {
        int k;
        cin >> k;
        map[i] = k;
        i++;
    }
    int answer = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        int j = 0;
        bool flag = true;
        while (j < v.size()) {
            int k = 0;
            int count = 0;
            while (k < n) {
                if (bit & (1 << k) && find(v[j].begin(), v[j].end(), k+1) != v[j].end()) {
                    count++;
                }
                k++;
            }
            if (count % 2 != map[j]) {
                flag = false;
                break;
            }
            j++;
        }
        if (flag) answer++;
    }
    cout << answer << endl;
}
