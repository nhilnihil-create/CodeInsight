#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"YES"<<endl;}else cout<<"NO"<<endl;//条件によってYes、Noを出力する
bool isK(string t){
    int n = t.length();
    for(int i=0;i<n;i++){
        if(t[i]!=t[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int n= s.length();
    string t = "";
    vector<int> lo;
    rep(i,n){
        if(s[i]!='x'){
            t += s[i];
            lo.push_back(i);
        }
    }
    if(t==""){
        cout<<0<<endl;
        return 0;
    }
    if(!isK(t)){
        cout<<-1<<endl;
        return 0;
    }
    int tn = t.length();
    //cout<<tn<<endl;
    //cout<<lo[tn/2]<<endl;//tnが奇数の時、真ん中の文字がsで出てくる場所
    //tnが偶数の時はlo[tn/2]とlo[tn/2-1]
    int ans=0;
        int l = lo[tn/2];
        if(tn%2==0){
            l = lo[tn/2-1];
        }
        int r = lo[tn/2];
        while(l>=0 || r<=n-1){
            if(l<0){
                r++;
                ans++;
            }
            else if(r>=n){
                l--;
                ans++;
            }
            else if(s[l]!=s[r]){
                if(s[l]=='x'){
                    l--;
                }
                if(s[r]=='x'){
                    r++;
                }
                ans++;
            }
            else if(s[l]==s[r]){
                r++;
                l--;
            }
        }
        cout<<ans<<endl;

}