#include<iostream>
#include<map>

using namespace std;

map<long long, long long> cnt;
long long ps[200005];

int main(){
    int N;
    long long ans = 0;
    cin >> N;
    ps[0] = 0;
    cnt[0] = 1;
    for(int i=1; i<=N; i++){
        long long num;
        cin >> num;
        ps[i] = num + ps[i-1];
        cnt[ps[i]]++;
        if(cnt[ps[i]] > 1){
            ans+= cnt[ps[i]] - 1;
        }
    }
    cout << ans << endl;
}