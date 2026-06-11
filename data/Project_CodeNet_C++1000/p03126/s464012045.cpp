#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> Point(M+1,0);
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        for(int j=0; j<K; j++){
            int tmp;
            cin >> tmp;
            Point[tmp] += 1;
        }
    }

    int count =0;
    for(int i=0; i<M+1; i++){
        if(Point[i] == N){
            count +=1;
        }
    }

    cout << count << endl;
    return 0;
}
