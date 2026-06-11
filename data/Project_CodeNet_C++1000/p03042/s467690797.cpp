#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}



int main(){
    string s; cin >> s;
    string s1=s.substr(0, 2), s2=s.substr(2, 2);
    int n=stoi(s1), m=stoi(s2);
    if(m >= 1 && m <= 12){
        if(n == 0 || n > 12) cout << "YYMM" << endl;
        else cout << "AMBIGUOUS" << endl;
    }
    else if(n >= 1 && n <= 12){
        if(m == 0 || m > 12) cout << "MMYY" << endl;
        else cout << "NA" << endl;
    }
    else cout << "NA" << endl;
    return 0;
}