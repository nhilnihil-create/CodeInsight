#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int N, M; cin >> N >> M;
    int i = 0;
    int index = 0;
    map<int, vector<int> > m;
    map<int, int> c;
    vector<int> p(M);
    vector<int> y(M);
    while(M > i){
        cin >> p[i] >> y[i];
        m[p[i]].push_back(y[i]);
        i++;
    }
    for (map<int, vector<int> >::iterator itr = m.begin(); itr != m.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
    }
    i = 0;
    while(M > i){
        string upper = to_string(p[i]);
        vector<int>::iterator itr;
        itr = find(m[p[i]].begin(), m[p[i]].end(), y[i]);
        string lower = to_string(distance(m[p[i]].begin(), itr) + 1);
        while (upper.length() < 6) {
            upper = "0" + upper;
        }
        while (lower.length() < 6) {
            lower = "0" + lower;
        }
        cout << upper + lower  << endl;
        i++;
    }
}
