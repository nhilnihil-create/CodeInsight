#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<string> vecN(N+10), vecM(M+10);
    for(int i=0; i<N; i++){
        cin >> vecN[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> vecM[i];
    }

    int result = 0;

    for(int i=0; i<N; i++){
        int count = 0;
        for(int j=0; j<N; j++){
            if(vecN[i] == vecN[j]) count++;
        }
        for(int j=0; j<M; j++){
            if(vecN[i] == vecM[j]) count--;
        }

        result = max(result, count);
    }

    cout << result << endl;


}