#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    map<char, int> m{};
    for(int i=0;i<N;i++){
        string s; cin >> s;
        m[s[0]]++;
    }
    long long ans =0;
    vector<long long> v(5);
    v[0] = m['M'];
    v[1] = m['A'];
    v[2] = m['R'];
    v[3] = m['C'];
    v[4] = m['H'];
    for(int i=0;i<=4;i++){
        for(int j=i+1;j<=4;j++){
            for(int k=j+1;k<=4;k++){
                ans += v[i]*v[j]*v[k];
            }
        }
    }
    cout << ans << endl;
}

