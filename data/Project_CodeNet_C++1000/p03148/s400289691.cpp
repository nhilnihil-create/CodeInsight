#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)

int main(){
    int N, K;
    cin >> N >> K;
    int t;
    long long d;
    vector<pair<long long, int> > pairs(N);
    rep(i, N){
        cin >> t >> d;
        pairs[i] = make_pair(d, t);
    }
    sort(pairs.begin(), pairs.end());
    set<int> s;
    int x = 0;
    long long sum = 0;
    long long M[K+1];
    fill_n(M, K+1, 0);
    priority_queue<long long , vector<long long>, greater<long long> > used;
    rep(i, K){
        int j = (N-1) - i;
        sum += pairs[j].first;
        if(!s.count(pairs[j].second)){
            s.insert(pairs[j].second);
            x++;
        }
        else{
            used.push(pairs[j].first);
        }
    }
    M[x] = sum;
    int j = N-K-1;
    int i = x;
    while(!used.empty()&& j >= 0){
        long long m = used.top();
        used.pop();
        while(j >= 0){
            if(!s.count(pairs[j].second)){
                s.insert(pairs[j].second);
                M[i+1] = M[i] - m + pairs[j].first;
                j--;
                break;
            }
            else j--;
        }
        i++;
    }
    priority_queue<long long> que;
    for(long long a = x; a <= i; a++){
        que.push(M[a] + a*a);
    }
    cout << que.top() << endl;
}