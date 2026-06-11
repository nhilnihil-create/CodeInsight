#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

int N;

void factor(map<int,int> &m, int num){
    for(int i=2; i*i <= num; i++){
        int p = 0;
        while(num%i==0){
            num /= i;
            p++;
        }
        if(p > 0){
            if(!m.count(i)) m[i] = 0;
            m.at(i) += p;
        }
    }
    if(num != 1){
        if(!m.count(num)) m[num] = 0;
        m.at(num)++;
    }
}

signed main(){
    cin >> N;
    map<int, int> div;
    reps(i,1,N) factor(div, i);
    
    vector<int> pows(76,0);
    for(auto p: div){
        if(p.second >= 74) pows[75]++;
        if(p.second >= 24) pows[25]++;
        if(p.second >= 14) pows[15]++;
        if(p.second >= 4)  pows[5]++;
        if(p.second >= 2)  pows[3]++;
    }
    
    int ans = 0;
    
    //a^75
    ans += pows[75];
    
    //a^3 * b^25
    ans += pows[3]*pows[25] - pows[25];
    
    //a^5 * b^15
    ans += pows[5]*pows[15] - pows[15];
    
    //a^3 * b^5 * c^5
    ans += (pows[3]-pows[5]) * max(0ll, pows[5]*(pows[5]-1)/2);
    ans += max(0ll, pows[5]*(pows[5]-1)*(pows[5]-2)/2);
    
    cout << ans << endl;
}