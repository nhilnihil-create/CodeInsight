#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, C;
pair<pair<int,int>, int> pro[100000];

signed main(){
	cin >> N >> C;
	rep(i, N){
		cin >> pro[i].first.first >> pro[i].first.second >> pro[i].second;
	}
	sort(pro, pro+N);

	rep(c, C){
		int rec[30];
		bool flg = true;
		rep(i, c+1) rec[i] = -1;
		rep(i, N){
			rep(j, c+1){
				if(rec[j] == -1 || pro[rec[j]].first.second < pro[i].first.first){
					rec[j] = i;
					break;
				}
				else if(pro[rec[j]].second == pro[i].second && pro[rec[j]].first.second <= pro[i].first.first){
					rec[j] = i;
					break;
				}
				if(j == c) flg = false;
			}
		}
		if(flg){
			cout << c+1 << endl;
			return 0;
		}
	}
}