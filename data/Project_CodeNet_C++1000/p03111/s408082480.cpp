#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t
ll N, a, b, c;
vector<ll> V;
ll ans = INF;


int main(){
    cin >> N >> a >> b >> c;
    V.resize(N);
    for(int i = 0; i < N; i++) cin >> V[i];

    for(int i = 1; i < (1<<N); i++){
        for(int j = 1; j < (1<<N); j++){
            for(int k = 1; k < (1<<N); k++){
                bitset<10> B1 = i;
                bitset<10> B2 = j;
                bitset<10> B3 = k;
                if(!(B1&B2).none() || !(B2&B3).none() || !(B3&B1).none()) continue;

                ll len1 = 0, len2 = 0, len3 = 0;
                ll mp1 = 0, mp2 = 0, mp3 = 0;
                for(int i = 0; i < N; i++) if(B1[i] == 1) len1 += V[i];
                for(int i = 0; i < N; i++) if(B2[i] == 1) len2 += V[i];
                for(int i = 0; i < N; i++) if(B3[i] == 1) len3 += V[i];
                mp1 += (B1.count()-1)*10;
                mp2 += (B2.count()-1)*10;
                mp3 += (B3.count()-1)*10;

                mp1 += abs(len1-a);
                mp2 += abs(len2-b);
                mp3 += abs(len3-c);
                ans = min(ans, mp1+mp2+mp3);
            }
        }
    }




    cout << ans << endl;
    

}

