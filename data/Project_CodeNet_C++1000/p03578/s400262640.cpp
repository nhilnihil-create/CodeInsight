#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main(){
    int N; cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> d[i];
    int M; cin >> M;
    vector<int> t(M);
    for(int i = 0; i < M; i++) cin >> t[i];
 
    sort(d.begin(), d.end());
    sort(t.begin(), t.end());
 
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        if(d[i] == t[cnt]) cnt++;
        if(cnt == M)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}