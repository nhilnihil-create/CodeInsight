#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;
int n, m;
int cnt = 0;
vector<set<int>> a;
vector<int> p;
bool check(vector<set<int>> b) {
    for (int i = 0; i < m; i++) {
        if (b[i].size() % 2 != p[i]) return false;
    }
    return true;
}

vector<int> subset;
void search(int k) {
    if (k == n) {
        vector<set<int>> b = a;
        for (int i = 0; i < (int)subset.size(); i++) {
            for (int j = 0; j < m; j++) {
                b[j].erase(subset[i]);
            }
        }
        if (check(b)) cnt++;
    }
    else {
        search(k + 1);
        subset.push_back(k+1);
        search(k + 1);
        subset.pop_back();
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        set<int> s;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        a.push_back(s);
    }
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    search(0);
    

    
    cout << cnt;
    return 0;
}