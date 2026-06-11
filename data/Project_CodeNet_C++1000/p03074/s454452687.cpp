
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> c; 
    int now=1; //今見ている数
    int cnt=0; //nowがいくつ並んでいるか
    rep(i,n){
        if(s[i] == (char)(now + '0')) cnt++;
        else{
            c.push_back(cnt);
            now=1-now; //0と1を切り替えるときの計算
            cnt = 1; //新しいのをカウントし始める
        }
    }
    c.push_back(cnt);
    //1で始まって2で終わるようにしたいので終端が0だったら適当に1つ足す
    if(c.size()%2==0) c.push_back(0);

    int m=c.size();
    vector<int> S(m+1); //sが累積和のベクトル
    rep(i,m) S[i+1] = S[i] + c[i];

    int ans=0;
    //1-0-1...の1から始めるので偶数番目だけを見る
    for(int i=0; i<m; i+=2){
        int left=i;
        int right=min(i+2*k+1,m);
        chmax(ans,S[right]-S[left]);
    }
    cout << ans << endl;





}