#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    string s;cin>>s;
    vector<pair<char, int>> le;
    // 後の計算用に、先頭と末尾を1にしておく
    int top = 0;
    if(s[0]=='0'){
        le.push_back(make_pair('1', 0));
        top++;
    }
    le.push_back(make_pair(s[0], 1));
    for(int i=1; i<n; i++){
        if(s[i] == le[top].first){
            le[top].second++;
        }else{
            le.push_back(make_pair(s[i], 1));
            top++;
        }
    }
    // 末尾も1にしておく
    if(le[le.size()-1].first == '0') le.push_back(make_pair('1', 0));
    int le_n = le.size();

    // 累積和作戦
    vector<int> sums(le_n+1, 0);
    for(int i=0; i<le_n; i++) sums[i+1] = sums[i]+le[i].second;

    int ans = 0;
    // 区間長k + (k+1)=2k+1の中で最大を求める
    for(int left=0; left<le_n; left+=2){ //偶数番スタートのみ考えればよい
        // cout<<left<<" "<<right<<endl;
        int right = left + 2*k+1;
        if(right >= sums.size()) right = sums.size()-1;
        ans = max(ans, sums[right]-sums[left]); 
    }
    cout<<ans<<endl;
}

// abc124_d