#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool se(int key, vector<long> &p, vector<bool> &q, vector<map<int, long>> &r){
    bool flag=true;
    for(auto itr=r[key].begin(); itr!=r[key].end(); ++itr){
        if(q[itr->first]){
            q[itr->first]=false;
            p[itr->first]=p[key]+itr->second;
            flag &= se(itr->first, p, q, r);
        }
        else flag &= p[itr->first]==p[key]+itr->second;
    }
    return flag;
}

int main() {
	int N, M; cin >> N >> M;
	vector<long> loc(N+1, 0);
	vector<bool> ch(N+1, true);
	vector<map<int, long>> v(N+1);
	for(int i=0; i<M; ++i){
	    int L, R;
	    long D;
	    cin >> L >> R >> D;
	    v[L][R]=D;
	    v[R][L]=-D;
	}
	bool ans=true;
	for(int i=1; i<=N; ++i){
	    if(ch[i]) ans &= se(i, loc, ch, v);
	}
	if(ans){
	    long mn=1e10, mx=-1e10;
	    for(int i=1; i<=N; ++i){
	        if(!ch[i]){
	            mn=min(mn, loc[i]);
	            mx=max(mx, loc[i]);
	        }
	    }
	    cout << (mx-mn<=1e9 ? "Yes" : "No") << endl;
	}
	else cout << "No" << endl;
	return 0;
}
