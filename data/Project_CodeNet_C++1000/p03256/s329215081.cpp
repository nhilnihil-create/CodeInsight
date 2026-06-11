#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v) {
    for(auto it=v.begin();it != v.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    return out;
}

int main() {
    int n,m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<vector<int>> v(n);
    vector<int> aok(n, 0);
    vector<int> bok(n, 0);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        if (s[a-1] == 'A') {
            aok[b-1]++;
        } else {
            bok[b-1]++;
        }
        v[a-1].push_back(b-1);
        if (a == b) {
            //continue;
        }
        if (s[b-1] == 'A') {
            aok[a-1]++;
        } else {
            bok[a-1]++;
        }
        v[b-1].push_back(a-1);
    }
    queue<int> q;
    for(int i=0;i<n;i++) {
        if (aok[i] == 0 || bok[i] == 0) {
            q.push(i);
        }
    }
    while(q.size() > 0) {
        int t = q.front();
        q.pop();
        //cout << t << endl;
        for(auto it = v[t].begin();it != v[t].end();it++) {
            if (aok[(*it)] == 0 || bok[(*it)] == 0) {
                continue;
            }
            if (s[t] == 'A') {
                aok[(*it)]--;
            } else {
                bok[(*it)]--;
            }
            if (aok[(*it)] == 0 || bok[(*it)] == 0) {
                q.push(*it);
            }
        }
    }
    //cout << aok << bok;
    for(int i=0;i<n;i++) {
        if(min(aok[i],bok[i])>0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}