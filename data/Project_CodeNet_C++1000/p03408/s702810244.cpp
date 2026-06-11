#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main(){
    int N,M;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
    cin >> M;
    vector<string> T(M);
    for(int j=0; j<M; j++){
        cin >> T[j];
    }

    set<string> S2(S.begin(), S.end());

    int max_count = 0;
    for(string target : S2){
        int count =0;
        for(int i=0; i<N; i++){
            if(S[i] == target){count++;}
        }
        for(int i=0; i<M; i++){
            if(T[i] == target){count--;}
        }

        if(count > max_count ){max_count = count;}

    }

    cout << max_count << endl;
    return 0;


}