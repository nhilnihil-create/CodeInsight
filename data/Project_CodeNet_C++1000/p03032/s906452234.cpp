#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, k;
vector<long long> V(55, 0);

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> V.at(i);

    int limit = min(n, k);
    long long vans = 0;
    for(int left = 0; left <= limit; ++left) {
        priority_queue <long long, vector<long long>, greater<long long>> pque;
        for(int i = 0; i < left; ++i) {
            pque.push(V.at(i));
        }

        for(int right = 0; right <= limit-left; ++right) {
            priority_queue<long long, vector<long long>, greater<long long>> ansque;
            ansque = pque;
            for(int j = 0; j < right; ++j) {
                ansque.push(V.at(n-1-j));
            }

            int dust = k-left-right;
            long long sum = 0;
            int now = 0;
            while(!ansque.empty() && now < dust) {
                if(ansque.top() < 0) {
                    ansque.pop();
                    now++;
                }else break;
            }

            while(!ansque.empty()) {
                sum += ansque.top();
                ansque.pop();
            }

            chmax(vans, sum);
        }
    }

    cout << vans << endl;
}