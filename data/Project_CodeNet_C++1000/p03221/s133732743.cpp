#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M; vector<vector<pair<int,int>>> P;
void input()
{
    cin >> N >> M;
    P.resize(N+1);
    for(int i=0; i<M; ++i){
        int p,y; cin >> p >> y;
        P[p].emplace_back(make_pair(y,i+1));
    }
}

string make_num(int i, int j)
{
    string ans="";
    int loop = 12;
    while(loop > 6){
        if(j > 0){
            ans += j%10 + '0';
            j /= 10;
        } 
        else ans += '0';
        --loop;
    }
    while(loop > 0){
        if(i > 0){
            ans += i%10 + '0';
            i /= 10;
        }
        else ans += '0';
        --loop;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    vector<pair<int,string>> C;
    for(int i=1; i<=N; ++i){
        sort(P[i].begin(),P[i].end());
        for(int j=0; j<P[i].size(); ++j){
            C.emplace_back(make_pair(P[i][j].second,make_num(i,j+1)));
        }
    }
    sort(C.begin(),C.end());
    for_each(C.begin(),C.end(),[](pair<int,string> p){
        cout << p.second << endl;
    });
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}