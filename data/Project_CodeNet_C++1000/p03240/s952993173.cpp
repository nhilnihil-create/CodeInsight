#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N; vector<pair<int,int>> P; vector<int> h;
void input()
{
    cin >> N;
    for(int i=0; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        P.emplace_back(make_pair(a,b));
        h.emplace_back(c);
    }    
}

void solve()
{
    for(int i=0; i<=100; ++i){
        for(int j=0; j<=100; ++j){
            int H;
            for(int k=0; k<N; ++k){
                if(h[k] > 0) {
                    H = abs(i-P[k].first) + abs(j-P[k].second) + h[k]; 
                    break;
                }
            }
            bool chk = true;
            for(int k=0; k<N; ++k){
                if(H != abs(i-P[k].first) + abs(j-P[k].second) + h[k]){
                    if(h[k] == 0 && H < abs(i-P[k].first) + abs(j-P[k].second)){
                        continue;
                    }
                    chk = false; break;
                }
            }
            if(chk){
                cout << i << " " << j << " " << H << endl;
                return;
            }
        }
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}