#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(123456789)
#define LINF (long long int)(123456789012345678)
#define MAX_V 1000

bool check(vector<int> a, int kind){
	//Aではない桁のみを入れてる
	map<int, int> mp;
	int memo = -1;
	//cout<<kind<<endl;
	rep(i,(int)a.size()){
		//cout<<memo<<" ";
		//for(auto itr = mp.begin(); itr != mp.end(); itr++){
			//cout<<"f: "<<itr->first<<" "<<itr->second<<" ";
		//}
		//cout<<endl;
		if(memo == a[i]){
			if(kind == 1){
				return false;
			}
			if((mp.find(memo) == mp.end() ? 1 : mp[memo]) < kind){
				if(mp.find(memo) == mp.end()){
					mp[memo] = 2;
				}else{
					mp[memo]++;
				}			
				continue;
			}else{
				mp.erase(memo);
				int memo2 = memo - 1;
				while(true){
					if(memo2 == 0){
						return false;
					}
					if((mp.find(memo2) == mp.end() ? 1 : mp[memo2]) < kind){
						if(mp.find(memo2) == mp.end()){
							mp[memo2] = 2;
						}else{
							mp[memo2]++;
						}
						break;
					}else{
						mp.erase(memo);
						memo2--;
					}
				}
			}
		}else if(memo > a[i]){
			if(kind == 1){
				return false;
			}
			for(auto itr = mp.begin(); itr != mp.end(); itr++){
				if(itr->first > a[i]){
					//cout<<itr->first<<endl;
					itr++;
					bool finish = false;
					if(itr == mp.end()){
						finish = true;
					}
					itr--;
					//itr++;
					mp.erase(itr);	
					if(finish){
						break;
					}
					//cout<<itr->first<<endl;
				}
			}
			//cout<<"hoge"<<endl;
			memo = a[i];
			//cout<<"hoge"<<endl;
			if((mp.find(memo) == mp.end() ? 1 : mp[memo]) < kind){
				if(mp.find(memo) == mp.end()){
					mp[memo] = 2;
				}else{
					mp[memo]++;
				}			
				continue;
			}else{
				mp.erase(memo);
				int memo2 = memo-1;
				while(true){
					if(memo2 == 0){
						return false;
					}
					if((mp.find(memo2) == mp.end() ? 1 : mp[memo2]) < kind){
						if(mp.find(memo2) == mp.end()){
							mp[memo2] = 2;
						}else{
							mp[memo2]++;
						}
						break;
					}else{
						mp.erase(memo);
						memo2--;
					}
				}
			}
		}else{
			memo = a[i];
		}
	}
	return true;
}

int main(void){
	int n,inp;
	cin>>n;
	vector<int> a;
	rep(i,n){
		cin>>inp;
		a.push_back(inp);
	}
	int down = 1, up = n+1;
	int now;
	while(up - down > 1){
		now = (up+down)/2;
		if(check(a,now)){
			up = now;
		}else{
			down = now;
		}
	}
	if(check(a, down)){
		cout<<down<<endl;
	}else{
		cout<<up<<endl;
	}
	

	return 0;
}




