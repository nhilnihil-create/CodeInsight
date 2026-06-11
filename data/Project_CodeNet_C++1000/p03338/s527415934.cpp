#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N; cin>> N;
    string S; cin>> S;

    int ans = 0;
    for(int i = 1; i < N; i++){
        int cnt = 0;

        for(char c = 'a'; c <= 'z'; c++){
            bool left = false, right = false;

            rep(j, i){
                if(S[j] == c) left = true;
            }
            for(int j = i; j < N; j++){
                if(S[j] == c) right = true;
            }

            if(left && right) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout<< ans << endl;
}
