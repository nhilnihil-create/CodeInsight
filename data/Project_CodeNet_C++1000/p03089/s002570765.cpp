#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int n;
    cin >> n;
    vector<int> b(n+1);
    vector<int> a(n);
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    bool ans=true;
    int t=0;
    //a.erase(a.begin()+i);で番目を削除 
    while(b.size()!=1){
        for(int j=b.size()-1;j>=0;j--){
            if(j==0){
                ans = false;
            }
            if(b[j]==j){
                b.erase(b.begin()+j);
                //cout<<j<<endl;
                a[t]=j;
                t++;
                break;
            }
        }
        if(!ans){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int j=t-1;j>=0;j--){
        cout<<a[j]<<endl;
    }
}