#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=3.14159265359;

int DP[10][10005]; // DP[使う数][桁数] = いくつ作ったか
bool okDP[10005];

int main() {
    int N, M;
    cin>>N>>M;
    vector<int> A(M);
    bool change;
    for(int i=0;i<M;++i){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    okDP[0] = true;
    map<int, int> match;
    match[1] = 2;
    match[2] = 5;
    match[3] = 5;
    match[4] = 4;
    match[5] = 5;
    match[6] = 6;
    match[7] = 3;
    match[8] = 7;
    match[9] = 6;
    int bef[10], aft[10];
    int befketa, aftketa;
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            if(match[A[j]] > i) continue;
            if(okDP[i-match[A[j]]] == false) continue;
            okDP[i] = true;
            for(int k=0;k<10;++k){
                bef[k] = DP[k][i];
                aft[k] = DP[k][i-match[A[j]]];
            }
            aft[A[j]]++;
            change = false;
            befketa = 0;
            aftketa = 0;
            for(int k=0;k<10;++k){
                befketa += bef[k];
                aftketa += aft[k];
            }
            if(befketa > aftketa) change = false;
            else if(befketa==aftketa) {
                for(int k=9;k>=0;--k){
                    if(aft[k]>bef[k]) {
                        change = true;
                        break;
                    }
                    if(aft[k]<bef[k]){
                        change = false;
                        break;
                    }
                }
            }
            else change = true;
            if(change){
                for(int k=0;k<10;++k){
                    DP[k][i] = aft[k];
                }
            }
        }
    }
    string ans;
    for(int i=9;i>=1;--i){
        for(int j=0;j<DP[i][N];++j){
            ans += i + '0';
        }
    }
    cout<<ans<<endl;
}
