#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};


int main(void){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    int t = 0;
    int ind = -1;
    for(int i = 0; i < N; i++){
        if(abs(a[i]) >= t){
            t = abs(a[i]);
            ind = i;
        }
    }
    vector<pair<int, int>> ANS;
    int ans = 0;
    if(a[ind] > 0){
        for(int i = 0; i < N; i++){
            if(a[i] < 0){
                a[i] += a[ind];
                ans++;
                ANS.push_back({i, ind});
            }
        }
        for(int i = 1; i < N; i++){
            if(a[i-1] > a[i]){
                int maxa = -1;
                int index = -1;
                for(int k = 0; k < N; k++){
                    if(a[k] > maxa){
                        maxa = a[k];
                        index = k;
                    }
                }
                a[i] += a[index];
                ans++;
                ANS.push_back({i, index});
            }
        }
        
    }else{
        for(int i = 0; i < N; i++){
            if(a[i] > 0){
                a[i] += a[ind];
                ans++;
                ANS.push_back({i, ind});
            }
        }
        
        for(int i = N-1; i >= 1; i--){
            if(a[i-1] > a[i]){
                int mini = 1;
                int index = -1;
                for(int k = 0; k < N; k++){
                    if(a[k] < mini){
                        mini = a[k];
                        index = k;
                    }
                }
                
                a[i-1] += a[index];
                ans++;
                ANS.push_back({i-1, index});
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < ANS.size(); i++){
        cout << ANS[i].second + 1 << " " << ANS[i].first + 1 << endl;
    }
    
}
