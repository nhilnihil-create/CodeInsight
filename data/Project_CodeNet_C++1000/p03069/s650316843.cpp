#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int ans = 1<<30;
    string S;
    cin>>N>>S;

    vector<int> white(N+1,0);
    vector<int> black(N+1,0);

    for(int i=0; i<N; ++i) {
        white[i+1] = white[i] + (S[i] == '.' ? 1 : 0);
        black[i+1] = black[i] + (S[i] == '#' ? 1 : 0);
    }


    for(int i=0; i<=N; i++){
        int b = black[i] - black[0];
        int w = white[N] - white[i];

        ans = min(b+w,ans);
    }    

    cout<<ans<<endl;

    return 0;
}