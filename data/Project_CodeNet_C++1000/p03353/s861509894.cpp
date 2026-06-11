#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
using namespace std;

int main(){
    string s;
    int K;
    cin >> s >> K;
    int t = s.size();
    priority_queue<string, vector<string>, greater<string>> pq;
    set<string> spq;
    for (int i = 0; i < t; i++){
        for (int j = 1; (j <= t - i && j <= 5); j++){
            string l = s.substr(i, j);
            if (!spq.count(l)){
                pq.push(l);
                spq.insert(l);
                
                if (pq.size() > 6){
                    vector<string> a(5);
                    for (int i = 0; i < 5; i++){
                        a.at(i) = pq.top();
                        pq.pop();
                    }
                    pq.pop();
                    for (int i = 0; i < 5; i++){
                        pq.push(a.at(i));
                    }
                }
                 
            }
        }
    }
    /*
    int h = pq.size();
    for (int i = 0; i < h; i++){
        string z = pq.top();
        pq.pop();
        cout << z << endl;
    }
     */
    for (int i = 0; i < K - 1; i++){
        pq.pop();
    }
    string z = pq.top();
    cout << z << endl;
}
