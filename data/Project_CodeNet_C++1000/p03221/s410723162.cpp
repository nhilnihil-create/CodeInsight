#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> A;
#define int long long
int N,M;
pair<int , int> K[100001];
signed main() {
    cin >> N >> M;
    vector<A>vec[100001];
    for(int i = 0; i < M; i++) {
        int P,Y;
        cin >> P >> Y;
        vec[P].push_back(A(Y,i));
    }
    for(int i = 1; i <= N; i++) {
        sort(vec[i].begin(),vec[i].end());
        for(int j = 0; j < vec[i].size(); j++){
        	K[vec[i][j].second].first = i;
       	    K[vec[i][j].second].second = j+1;
        }
    }
    for(int i = 0; i < M; i++) {
        printf("%06d" "%06d\n",K[i].first,K[i].second);
    }
}