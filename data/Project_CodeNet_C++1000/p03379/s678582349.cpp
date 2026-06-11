#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main(){
    int N; cin >> N;
    vector<long long> v1(N);
    vector<long long> v2(N);
    for(int i=0;i<N;i++) cin >> v2[i];
    v1 = v2;
    sort(v2.begin(),v2.end());
    long long a = v2[N/2];
    long long b = v2[N/2-1];
    for(int i=0;i<N;i++){
        if(v1[i] < a) cout << a << endl;
        else cout << b << endl;
    }
}
