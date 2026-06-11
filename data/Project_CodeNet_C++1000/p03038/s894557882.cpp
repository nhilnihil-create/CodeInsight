#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    
    int N,M;
    cin >> N >> M;
    vector<pair<long long,long long>> vec(N);
    long long A;
    for(int i = 0; i < N;i++){
        cin >> A;
        vec[i] = make_pair(A,0);
    }
    sort(vec.begin(),vec.end());
    
    long long B,C;
    vector<pair<long long,long long>> change(M);    
    for(int i = 0; i < M;i++){
        cin >> B >> C;
        change[i] = make_pair(C,B);
    }
    
    sort(change.begin(),change.end(),greater<pair<long long,long long>>());
    
    int index = 0;
    for(int i = 0; i < M;i++){
        
        while(change[i].first > vec[index].first&&change[i].second>0){
            vec[index].first = change[i].first;
            index++;
            change[i].second--;
        }
        
        
    }
    
    long long ans = 0;
    for(int i = 0; i < N;i++){
        ans += vec[i].first;
    }
    
    cout << ans << endl;
}

