#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

	string str;
	cin >> str;

	LL x,y;

	cin >> x >> y;

	LL ofs = 8000;
	vector<LL> t;
	LL tmp = 0;
	for(int i = 0; i < str.size();i++){
		if(str[i] == 'F'){
			tmp++;
		}else{
			t.push_back(tmp);
			tmp = 0;
		}
	}
	if(tmp != 0){
		t.push_back(tmp);
	}
	vector<vector<bool>> dpx((t.size()+1)/2+2,vector<bool>(16001,false));
	dpx[0][ofs] = true;
	LL indx = 1;
	for(int i = 0; i < t.size(); i += 2){
		for(int j = 0; j < 16001; j++){
			if(dpx[indx-1][j]){
				if(i > 0 && j - t[i] >= 0){
					dpx[indx][j-t[i]] = true;
				}
				if(j + t[i] < 16001){
					dpx[indx][j+t[i]] = true;
				}
			}
		}
		indx++;
	}

	vector<vector<bool>> dpy((t.size()+1)/2+2,vector<bool>(16001,false));
	dpy[0][ofs] = true;
	LL indy = 1;
	for(int i = 1; i < t.size(); i += 2){
		for(int j = 0; j < 16001; j++){
			if(dpy[indy-1][j]){
				if(j - t[i] >= 0){
					dpy[indy][j-t[i]] = true;
				}
				if(j + t[i] < 16001){
					dpy[indy][j+t[i]] = true;
				}
			}
		}
		indy++;
	}

	if(dpx[indx-1][ofs+x] && dpy[indy-1][ofs+y]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}


	
    
    return 0;
}