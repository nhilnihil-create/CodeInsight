#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;
const int H_MAX = 510;
const int W_MAX = 510;
int H,W;
vector<vector<int>> a(H_MAX,vector<int>(W_MAX,0));

int main(){
    string S,T;
    cin >> S >> T;
    vector<int> cnt_s(26),cnt_t(26);
    rep(i,S.size()){
        cnt_s[S[i]-'a']++;
        cnt_t[T[i]-'a']++;
    }
    sort(cnt_s.begin(),cnt_s.end());
    sort(cnt_t.begin(),cnt_t.end());
    rep(i,26){
        if(cnt_s[i]!=cnt_t[i]){
            cout << "No" << endl;  
            return 0;
        }
    }

    cout << "Yes" << endl;

}
