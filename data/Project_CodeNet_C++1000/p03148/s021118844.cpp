#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>
#include<map>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++) 
#define lint long long
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> P;

const int MAX_S = 100001;
bool used[MAX_S];

bool comp(P x, P y){
    return x.second > y.second;
}

int main(){
    int n, k; cin >> n >> k;
    vector<P> sushi(n);
    rep(i, n){
        int t; long d; cin >> t >> d;
        sushi[i] = make_pair(t, d);
    }
    sort(all(sushi), comp);
    
    long sum = 0; long count = 0;
    multiset<long> q;
    rep(i, k){
        sum += sushi[i].second;
        if (!used[sushi[i].first]){
            count++;
            used[sushi[i].first] = true;
        }
        else{
            q.insert(sushi[i].second);
        }
    }
    long ans = sum + count * count;
    
    for(int i = k; i < n; i++){
        P s = sushi[i];
        if(used[s.first]) continue;
        else{
            if(q.empty()) break;

            used[s.first] = true;
            sum -= *(q.begin());
            q.erase(q.begin());
            sum += s.second;
            count++;
            long newans = sum + count * count;
            ans = max(ans, newans);
        }
    }
    cout << ans << endl;
}