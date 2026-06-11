#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<int> graph[10010];
    for(int i = 0;i < N - 1;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    vector<int> count(N);
    for(int i = 0;i < N;i++) {
        count.at(i) = graph[i].size();
    }
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    vector<ll> ret(N);
    vector<bool> used(N);
    for(int i = 0;i < N;i++) {
        int cnt = 0;
        int cnt2 = Inf;
        for(int j = 0;j < N;j++) {
            if(used.at(j) == false && cnt2 > count.at(j)) {
                cnt = j;
                cnt2 = count.at(j);
            }
        }
        ret.at(cnt) = vec.at(i);
        used.at(cnt) = true;
        for(int j = 0;j < graph[cnt].size();j++) {
            count.at(graph[cnt].at(j))--;
        }
    }
    ll ret2 = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < graph[i].size();j++) {
            ret2 += min(ret.at(i),ret.at(graph[i].at(j)));
        }
    }
    cout << ret2 / 2 << endl;
    for(int i = 0;i < N;i++) {
        cout << ret.at(i) << " ";
    }
    cout << endl;
}