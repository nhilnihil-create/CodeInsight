#include<bits/stdc++.h>
using namespace std;

int h, w, n;

void check(vector<int> &boundary) {
    if (boundary[0] < 0) boundary[0]++;
    if (boundary[1] >= h) boundary[1]--;
    if (boundary[2] >= w) boundary[2]--;
    if (boundary[3] < 0) boundary[3]++;
}

int main(){
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    sr--;
    sc--;
    string s, t;
    cin >> s >> t;
    vector<char> s_direction = {'U', 'D', 'R', 'L'};
    vector<char> t_direction = {'D', 'U', 'L', 'R'};
    vector<int> boundary(4, 0);
    boundary[1] = h - 1;
    boundary[2] = w - 1;
    vector<int> ds = {1, - 1, - 1, 1};
    vector<int> dt = {- 1, 1, 1, - 1};
    for (int i = 0; i < 4; i++){
        if (s[n - 1] == s_direction[i]) {
            boundary[i] += ds[i];
            check(boundary);
        }
    }

    for (int i = n - 2; i >= 0; i--){
        for (int j = 0; j < 4; j++) {
            if (t[i] == t_direction[j]) {
                boundary[j] += dt[j];
                check(boundary);
            }
        }
        for (int j = 0; j < 4; j++) {
            if (s[i] == s_direction[j]) {
                boundary[j] += ds[j];
                check(boundary);
            }
        }
        if (boundary[0] >= h || boundary[1] < 0 || boundary[2] < 0 || boundary[3] >= w) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    if (boundary[0] <= sr && sr <= boundary[1] && boundary[3] <= sc && sc <= boundary[2]) cout << "YES" << endl;
    else cout << "NO" << endl;
}