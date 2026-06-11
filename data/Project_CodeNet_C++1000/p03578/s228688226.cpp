#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}


int main(){
    int N; cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> d[i];
    int M; cin >> M;
    vector<int> t(M);
    for(int i = 0; i < M; i++) cin >> t[i];

    sort(d.begin(), d.end());
    sort(t.begin(), t.end());

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(d[i] == t[cnt]) cnt++;
        
        if(cnt == M){
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    return 0;
}
