#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> R(N);
    vector<pair<int,int>> B(N);
    bool F[N] = {};
    int a,b;
    rep(i,N){
        cin >> a >> b;
        R[i] = make_pair(b,a);
    }
    rep(i,N){
        cin >> a >> b;
        B[i] = make_pair(a,b);
    }
    sort(R.begin(),R.end());
    sort(B.begin(),B.end());
    int count = 0;
    rep(i,B.size()){
        for(int j=R.size()-1;0<=j;j--){
            if(R[j].first < B[i].second && R[j].second < B[i].first && !F[j]){
                F[j] = true;
                count++;
                break;
            }
        }
    }
    cout << count << endl;

    return 0;
}