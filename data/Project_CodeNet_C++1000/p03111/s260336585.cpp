#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    int N,A,B,C; cin>>N>>A>>B>>C;
    int l[10];
    for(int i=0;i<N;i++) cin >> l[i];

    int ans = 1001001001;
    for(int i=0;i<(1 << 2*N);i++){
        vector<int> a,b,c;
        for(int j=0;j<2*N;j+=2){
            int t = (i >> j) & 0b11;
            if(t == 1) a.push_back(l[j/2]);
            else if(t == 2) b.push_back(l[j/2]);
            else if(t == 3) c.push_back(l[j/2]); 
        }
        if((int)a.size() < 1 || (int)b.size() < 1 || (int)c.size() < 1) continue;

        int sum_a = 0;
        int sum_b = 0;
        int sum_c = 0;
        for(int d:a) sum_a += d;
        for(int d:b) sum_b += d;
        for(int d:c) sum_c += d;
        int cost_a = abs(sum_a - A) + 10*((int)a.size() - 1);
        int cost_b = abs(sum_b - B) + 10*((int)b.size() - 1);
        int cost_c = abs(sum_c - C) + 10*((int)c.size() - 1);

        ans = min(ans, cost_a + cost_b + cost_c);
    }
    cout << ans << endl;
    return 0;
}