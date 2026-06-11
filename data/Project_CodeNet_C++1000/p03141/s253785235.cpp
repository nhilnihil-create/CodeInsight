#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>


using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<pair<long long, long long>> val(N);
    for(int i = 0; i < N; i++){
        long long A,B;
        cin >> A >> B;
        val[i].first = A + B;
        val[i].second = B;
    }
    sort(val.begin(),val.end());
    int count = 0;
    if(N % 2 == 0){
        count = N / 2;
    }else{
        count = (N - 1)/2 + 1;
    }
    long long result = 0;
    for(int i = 0; i <N; i++){
        if(i % 2 == 0){
            result += val[N - i - 1].first;
        }else{

        }
    }
    for(int i =0; i < N; i++){
        result -= val[i].second;
    }
    cout << result << endl;

}