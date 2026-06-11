#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,anss=1,ans=1;
    cin >> N;
    vector<int> P(N);
    for(int i=0;i<N;i++){
        int p;
        cin >> p;
        P[p-1] = i;
    }

    for(int i=1;i<N;i++){
        if(P[i-1]<P[i]){
            anss++;
        }else{
            ans = max(ans,anss);
            anss = 1;
        }
    }

    ans = max(ans,anss);

    cout << N-ans << endl;
}