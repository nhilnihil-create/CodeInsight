
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

//好きな数字を書き換える=邪魔な数字を無視する
//最大公約数はどこから計算しても変わらない
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<int> lgcd(n); //A[i]より左側にある数字のgcd
    vector<int> rgcd(n); //A[i]より右側にある数字のgcd
    
    lgcd[0]=a[0];
    for(int i=1;i<n;i++) lgcd[i] = gcd(lgcd[i-1],a[i-1]);

    rgcd[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--) rgcd[i] = gcd(rgcd[i+1],a[i+1]);

    int ans=0;

    //両橋(i=0とi=n-1)は別処理にする
    ans = max(ans,rgcd[0]);
    for(int i=1;i<n-1;i++){
        ans = max(ans,gcd(lgcd[i],rgcd[i]));
    }
    ans=max(ans,lgcd[n-1]);

    cout << ans << endl;





}