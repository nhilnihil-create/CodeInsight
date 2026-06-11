#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>

#define N_size 100000000000

using namespace std;

int main(){
    int N,M;
    cin >> N;

    vector<long long> D(N);

    for(int i = 0;i < N;i++){
        cin >> D.at(i);
    }

    cin >> M;

    vector<long long> T(M);

    for(int i = 0;i < M;i++)
        cin >> T.at(i);

    map<int ,int> mpa,mpb;

    for(int i = 0;i < N;i++)
        mpa[D.at(i)]++;
    for(int i = 0;i < M;i++)
        mpb[T.at(i)]++;

    for(int i = 0;i < M;i++){
        int x = T.at(i);
        if(mpb[x] > mpa[x]){
            cout << "NO"  << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;

}
