#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> march(5, 0);
    for(long long i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s[0] == 'M') march[0]++;
        else if(s[0] == 'A') march[1]++;
        else if(s[0] == 'R') march[2]++;
        else if(s[0] == 'C') march[3]++;
        else if(s[0] == 'H') march[4]++;
    }

    long long cnt = 0;
    for(long long i = 0; i < 5; i++){
        for(long long j = i + 1; j < 5; j++){
            for(long long k = j + 1; k < 5; k++){
                cnt += march[i]*march[j]*march[k];
            }
        }
    }
    cout << cnt << endl;
    return 0;
}