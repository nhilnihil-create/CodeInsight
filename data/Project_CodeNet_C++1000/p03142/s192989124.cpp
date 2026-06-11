#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
//typedef vector<int> VI;

#define FOR(i, a, n) for (long long i = (long long)a; i < (long long)n; ++i)
#define REP(i, n) FOR(i, 0, n)

//グラフの隣接リスト
//VI g[100010];
vector<int> G[100010];
//頂点の入次数を管理
//int h[100010];
int indeg[100010];

signed main()
{
    //頂点数v、辺の数e
    int n, m;
    cin >> n >> m;
    vector<int> revG[n];
    REP(i, n+m-1) {
        int s, t;
        cin >> s >> t;
        s--;t--;
        //頂点sから頂点tへの有向辺
        G[s].push_back(t);
        revG[t].push_back(s);
        indeg[t]++;
    }
    
    //入次数が0の頂点の集合を格納するスタック
    stack<int> st;
    
    //入次数が0の頂点であればstに追加
    REP(i, n) if(indeg[i] == 0) st.push(i);
    
    //ソートされた後のグラフの頂点の列
    vector<int> seq;
    //stがなくなるまでループ
    while(st.size()) {
        //stの集合のから一つ取り出す
        int i = st.top(); st.pop();
        seq.push_back(i);
        for(auto& j: G[i]) {
            //隣接する頂点の入次数をマイナス1
            indeg[j]--;
            //これによって入次数が0になればstに追加
            if(indeg[j] == 0) st.push(j);
        }
    }
    
    vector<int> order(n);//頂点iがseq内で何番目か
    REP(i,n){
      order[seq[i]] = i;
    }
    vector<int> ans(n);
    int temp;
    int par;
    REP(i,n){
      temp = -1;
      for(auto& j:revG[i]){
        if(temp<order[j]){
          temp = order[j];
          par = j;
        }
      }
      if(temp==-1){
        ans[i] = 0;
      }else{
        ans[i] = par+1;
      }
    }
    
    REP(i,n){
      cout<<ans[i]<<endl;
    }
    return 0;
}
