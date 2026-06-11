#include <iostream>
#include <vector>
#include <map>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    bool fp[N+1];
    vector<int> p;
    fill(fp, fp+N+1, true);
    for(int i=2; i<=N; i++){
        if(!fp[i]) continue;
        p.push_back(i);
        int t = 2*i;
        while(t <= N){
            fp[t] = false;
            t += i;
        }
    }
    

    map<int, int> m;
    for(auto prime : p){
        m[prime] = 0;
        for(int i=2; i<=N; i++){
            int t = i;
            while(t % prime == 0){
                m[prime]++;
                t /= prime;
            }
        }
    }

    long dp[p.size()+1][76];
    for(int i=0; i<p.size()+1; i++){
        for(int j=0; j<=75; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    for(int i=0; i<p.size(); i++){
        for(int j=1; j<=75; j++){
            for(int k=0; k<=m[p[i]]; k++){
                if(j*(k+1)>75) continue;
                dp[i+1][j*(k+1)] += dp[i][j];
            }
        }
    }

    cout << dp[p.size()][75] << endl;

    return 0;
}
