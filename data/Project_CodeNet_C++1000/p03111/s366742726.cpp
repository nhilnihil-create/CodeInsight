#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int A,B,C;
vector<int> l;
int ans = 1001001001;

void dfs(vector<int> d){
    if(d.size()==N){
        vector<int> material(3,0);
        int point = 0;
        for(int i=0;i<N;i++){
            if(d[i]==3) continue;
            if(material[d[i]]!=0) point += 10;
            material[d[i]] += l[i];
        }
        if(material[0]*material[1]*material[2]==0) return;
        
        point += abs(A-material[0]) + abs(B-material[1]) + abs(C-material[2]);
        ans = min(ans,point);
        return;
    }

    for(int i=0;i<4;i++){
        d.push_back(i);
        dfs(d);
        d.pop_back();
    }
}

int main(void){
    cin >> N >> A >> B >> C;
    l.resize(N);
    for(int i=0;i<N;i++) cin >> l[i];
    dfs({});
    cout << ans << endl;
}