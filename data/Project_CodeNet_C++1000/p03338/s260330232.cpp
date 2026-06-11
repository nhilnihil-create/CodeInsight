#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    string S; cin>>S;

    int ans=0;
    for(int i=0; i<N-1; i++){
        int re=0;
        map<char,int> moji;
        // 左側
        for(int j=0; j<=i; j++){
            moji[S[j]]=1;
        }
        // 右側ループして一致カウント
        for(int k=i+1; k<N; k++){
            if(moji.count(S[k]) && moji[S[k]]==1){
                re++;
                moji[S[k]]=2;
            }
        }
        ans = max(ans,re);
    }
    cout << ans << endl;
}
