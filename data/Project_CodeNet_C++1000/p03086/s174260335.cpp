#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    
    string S;
    cin >>S;
    ll N = S.size();
    ll cnt = 0, max = 0;
    rep(i,N){
        if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
            cnt++;
        }else{
            if(cnt > max){
                max = cnt;
            }
            cnt = 0;
        }
    }
    if(cnt > max){
        max = cnt;
    }
    cout << max << endl;
    
    
    
    return 0;
    

}