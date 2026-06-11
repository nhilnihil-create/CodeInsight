#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[505][505];

//dpTable
//bool dp[100050];

int main(){
    string S;
    cin >> S;
    bool YYMM = false,MMYY = false;
    //YYMM
    if (S.at(2) == '0' && S.at(3) != '0') YYMM = true;
    else if (S.at(2) == '1') {
        if (S.at(3) == '0' ||S.at(3) == '1' || S.at(3) == '2') YYMM = true;
    }
    //MMYY
    if (S.at(0) == '0' && S.at(1) != '0') MMYY = true;
    else if (S.at(0) == '1') {
        if (S.at(1) == '0' ||S.at(1) == '1' || S.at(1) == '2') MMYY = true;
    }
    if (YYMM && MMYY) cout << "AMBIGUOUS" << endl;
    else if (YYMM) cout << "YYMM" << endl;
    else if (MMYY) cout << "MMYY" << endl;
    else cout << "NA" << endl;
    return 0;
}