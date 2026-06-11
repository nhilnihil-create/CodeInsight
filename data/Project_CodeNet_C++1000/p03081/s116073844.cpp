#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int N, Q;
string s;
vector<string> v;

int check(long long int pos){
    char c = s[pos];
    for(int i = 0; i < Q; i++){
        if(v[i][0] == c){
            if(v[i][1] == 'L'){
                pos -= 1;
            }else{
                pos += 1;
            }
        }
        if(pos < 0){
            return 0;
        }
        if(pos >= N){
            return 2;
        }
        c = s[pos];
    }
    return 1;
}

long long int bin_search(long long int lef, long long int rig, int num){
	long long int middle = (lef + rig) / 2;
	//cout << middle << " ";
	if(rig - lef <= 1){
        return lef;
	}
	if(check(middle) == num){
		lef = middle;
	}else{
		rig = middle;
	}
	return bin_search(lef, rig, num);
}

int main(){
    cin >> N >> Q;
    cin >> s;
    for(int i = 0; i < Q; i++){
        string t, d;
        cin >> t >> d;
        v.push_back(t + d);
    }
    long long int pos1 = bin_search(-1, N, 0);
    long long int pos2 = bin_search(pos1, N, 1);
    cout << pos2 - pos1 << endl;
    return 0;
}